/***********************************************************************
 * Module:  UpdateGridB.cpp
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Implementation of the class UpdateGridB
 ***********************************************************************/

#include "UpdateGridB.h"

////////////////////////////////////////////////////////////////////////
// Name:       UpdateGridB::UpdateGrid(int particleNum, Particle* particles)
// Purpose:    Implementation of UpdateGridB::UpdateGrid()
// Parameters:
// - particleNum
// - particles
// Return:     void
////////////////////////////////////////////////////////////////////////
////UpdateGrid
const int INITIAL_GRID_CAPACITY = 60;
void UpdateGridB::sph_neighbour_list_create(sph_neighbour_list* l, int n_particles){
	l->sizes =new int[n_particles]();
	l->pool = malloc(250*n_particles*sizeof(sph_neighbour));
	l->p =new sph_neighbour*[n_particles];
}
void UpdateGridB::sph_grid_create(sph_grid* g, int n_particles, float grid_len){
	int g_size;
	g->capacity = 40*40*40;
	g_size = g->capacity;

	g->sizes =new int[g_size]();
	g->caps =new int[g_size]();

	g->particles =new int*[g_size];

	for (int i = 1; i < g_size; i++){
		g->caps[i] = 0;
	}
	g->grid_len = grid_len;

	g->mempool.capacity = sizeof(int)*80*80*INITIAL_GRID_CAPACITY;
	g->mempool.prealloc =malloc(sizeof(int)*80*80*INITIAL_GRID_CAPACITY);
	g->mempool.used_size = 0;
}
void* UpdateGridB::sph_mem_pool_alloc(sph_mem_pool* pool, int size){
	void* ret;
	ret = &(((char*)pool->prealloc)[pool->used_size]);
	pool->used_size += size;
	return ret;
}
void UpdateGridB::sph_grid_clear(sph_grid* g, int start, int end, Particle* particles){
	float fmin_x;
	float fmax_x;
	float fmin_y;
	float fmax_y;
	float fmin_z;
	float fmax_z;

	fmin_x = fmin_y = fmin_z = MAX_FLOAT;
	fmax_x = fmax_y = fmax_z = -MAX_FLOAT;
	for (int i = start; i <= end; i++){
		const vector3* p = &particles[i].curPos;
		if (fmin_x > p->x)
			fmin_x = p->x;
		if (fmax_x < p->x)
			fmax_x = p->x;
		if (fmin_y > p->y)
			fmin_y = p->y;
		if (fmax_y < p->y)
			fmax_y = p->y;
		if (fmin_z > p->z)
			fmin_z = p->z;
		if (fmax_z < p->z)
			fmax_z = p->z;
	}

	g->width  = (int)((fmax_x - fmin_x + g->grid_len)/g->grid_len);
	g->height = (int)((fmax_y - fmin_y + g->grid_len)/g->grid_len);
	g->depth  = (int)((fmax_z - fmin_z + g->grid_len)/g->grid_len);

	g->minx = fmin_x;
	g->miny = fmin_y;
	g->minz = fmin_z;

	if (g->width*g->height*g->depth > g->capacity)
		printf("Out of Capacity\n");

	memset(g->sizes, 0, g->width*g->height*g->depth*sizeof(int));
	memset(g->caps, 0, g->width*g->height*g->depth*sizeof(int));

	g->mempool.used_size = 0;
}
void UpdateGridB::sph_grid_alloc(sph_grid* g, int start, int end, Particle* particles){
	float inv_glen = 1.0f/g->grid_len;
	for (int i = start; i <= end; i++){
		int gx;
		int gy;
		int gz;
		int gindex;

		//particles[i].curPos = particles[i].curPos;
		gx = (int)((particles[i].curPos.x - g->minx) *inv_glen);
		gy = (int)((particles[i].curPos.y - g->miny) *inv_glen);
		gz = (int)((particles[i].curPos.z - g->minz) *inv_glen);

		gindex = gx + gy*g->width + gz*g->width*g->height;

		if (g->sizes[gindex] == g->caps[gindex]){
			g->particles[gindex] = (int*)sph_mem_pool_alloc(&g->mempool, 50*sizeof(int));
			g->caps[gindex] = 50;
		}

		g->particles[gindex][g->sizes[gindex]] = i;
		g->sizes[gindex]++;
	}
}
void UpdateGridB::sph_grid_get_neighbours(sph_grid* g, int start, int end, sph_neighbour_list* n_list, float search_radius, Particle* particles)
{
	int neighbour_grid;
	int gx;
	int gy;
	int gz;
	int gindex;
	int pindex;
	float search_radius2;

	float inv_glen;
	vector3 dist;

	n_list->n_poolused = n_list->used_by_rigid;
	search_radius2 = search_radius*search_radius;

	inv_glen = 1.0f/g->grid_len;
	for (int i = start; i <= end; i++)
	{
		n_list->p[i] = &((sph_neighbour*)n_list->pool)[n_list->n_poolused];
		n_list->p[i][0].index = i;
		n_list->sizes[i] = 1;
		gx = (int)((particles[i].curPos.x - g->minx)*inv_glen);
		gy = (int)((particles[i].curPos.y - g->miny)*inv_glen);
		gz = (int)((particles[i].curPos.z - g->minz)*inv_glen);

		gindex = gx + gy*g->width + gz*g->width*g->height;
		for (gz = -1; gz <= 1; gz++)
			for (gy = -1; gy <= 1; gy++)
				for (gx = -1; gx <= 1; gx++)
				{
					neighbour_grid = gindex + g->width*g->height*gz + g->width*gy + gx;
					if ((neighbour_grid < 0) || (neighbour_grid >= g->width*g->depth*g->height))
						continue;

					for (int j = 0; j < g->sizes[neighbour_grid]; j++)
					{
						float distsq;

						pindex = g->particles[neighbour_grid][j];
						dist = particles[i].curPos - particles[pindex].curPos;
						distsq=dist.lengthSqr();

						if (distsq < search_radius2)
						{
							int nindex = n_list->sizes[i];
							n_list->p[i][nindex].index = pindex;
							n_list->sizes[i]++;
						}
					}
				}

				if (g->sizes[gindex] == g->caps[gindex])
				{
					g->particles[gindex] = (int*)sph_mem_pool_alloc(&g->mempool, 150*sizeof(int));
					g->caps[gindex] = 150;
				}

				n_list->n_poolused += n_list->sizes[i];
				g->particles[gindex][g->sizes[gindex]] = i;
				g->sizes[gindex]++;
	}
}
void UpdateGridB::UpdateGrid(int particleNum, Particle* particles)
{
   // TODO : implement
    static bool isFirst = 1;
    if(isFirst){
        sph_neighbour_list_create(&n_list, particleNum);
        sph_grid_create(&grid, particleNum, SMOOTHING_LENGTH);
    }
    isFirst = 0;
    sph_grid_clear(&grid, 0, particleNum - 1, particles);
    sph_grid_alloc(&grid, 0, 0 - 1, particles);
    sph_grid_get_neighbours(&grid, 0, particleNum - 1, &n_list, SMOOTHING_LENGTH, particles);
    //
    const float h2 = SMOOTHING_LENGTH*SMOOTHING_LENGTH;
    sph_neighbour_list* nlist = &n_list;
    for (int i = 0; i < particleNum; i++){
        particles[i].neighbour_count = 0;
        for (int j = 0; j < nlist->sizes[i]; j++){
            int nindex = nlist->p[i][j].index;
            vector3 dist = particles[i].curPos - particles[nindex].curPos;
            float distsq = dist.lengthSqr();
            if (distsq < h2){
                particles[i].neighbours[particles[i].neighbour_count] = nindex;
                particles[i].r[particles[i].neighbour_count] = sqrt(distsq);
                particles[i].neighbour_count ++;
            }
        }
    }
	std::cout << "end" << std::endl;
}

UpdateGridStrategy * UpdateGridB::Create()
{
	return new UpdateGridB;
}

void UpdateGridB::ExportClass()
{
	class_<UpdateGridB, bases<UpdateGridStrategy> >("UpdateGridB", init<>())
		.def("UpdateGrid", &UpdateGridB::UpdateGrid)
		.def("Create", &UpdateGridB::Create, return_value_policy<manage_new_object>())
		.staticmethod("Create");
}