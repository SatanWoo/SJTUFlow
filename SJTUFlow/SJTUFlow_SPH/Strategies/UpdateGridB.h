/***********************************************************************
 * Module:  UpdateGridB.h
 * Author:  zs
 * Modified: 2013Äê11ÔÂ21ÈÕ 20:26:47
 * Purpose: Declaration of the class UpdateGridB
 ***********************************************************************/

#if !defined(__SJTUFLOW2_UpdateGridB_h)
#define __SJTUFLOW2_UpdateGridB_h

#include "../utils.h"
#include "../Particle.h"
#include "../UpdateGridStrategy.h"

class UpdateGridB : public UpdateGridStrategy
{
public:
   void UpdateGrid(int particleNum, Particle* particles);

   static UpdateGridStrategy *Create();
   static void ExportClass();

protected:
private:
    typedef struct
    {
        int index;
    }sph_neighbour;

    typedef struct
    {
        void* prealloc;
        int used_size;
        int capacity;
    }sph_mem_pool;

    typedef struct
    {
        int* sizes;
        sph_neighbour **p;
        void* pool;
        int used_by_rigid;
        int n_poolused;
    }sph_neighbour_list;

    typedef struct
    {
        int ** particles;
        int* sizes;
        int* caps;
        int capacity;
        int width;
        int height;
        int depth;
        float grid_len;

        float minx;
        float miny;
        float minz;

        sph_mem_pool mempool;
    }sph_grid;

    sph_neighbour_list n_list;
    sph_grid grid;

    void sph_neighbour_list_create(sph_neighbour_list* l, int n_particles);
    void sph_grid_create(sph_grid* g, int n_particles, float grid_len);
    void* sph_mem_pool_alloc(sph_mem_pool* pool, int size);
    void sph_grid_clear(sph_grid* g, int start, int end, Particle* particles);
    void sph_grid_alloc(sph_grid* g, int start, int end, Particle* particles);
    void sph_grid_get_neighbours(sph_grid* g, int start, int end, sph_neighbour_list* n_list, float search_radius, Particle* particles);
};

#endif
