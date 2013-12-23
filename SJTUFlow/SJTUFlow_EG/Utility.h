#ifndef _UTILITY_H
#define _UTILITY_H

#define IX(i,j) ((i)+(N+2)*(j))
#define IX_S(i,j,N) ((i)+(N+2)*(j))
#define IX3D(i,j,k) ((i)+(N+2)*(j)+(N+2)*(N+2)*(k))
#define IX3D_S(i,j,k,N) ((i)+(N+2)*(j)+(N+2)*(N+2)*(k))
#define SWAP(x0,x) {float * tmp=x0;x0=x;x=tmp;}
#define FOR_EACH_CELL for ( i=1 ; i<=N ; i++ ) { for ( j=1 ; j<=N ; j++ ) {
#define END_FOR }}

#endif