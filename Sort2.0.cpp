#include <stdio.h>
#include <math.h>

typedef struct koordunatu{
    int x;
    int y;
    int z;
    double result;
}koord;

int to_vvid (koord pm[], int n){
  int a, xx, yy, zz, xyz;
  printf("VVedit vashi koordunatu:\n");
  for (a=0; a<n; a++){
    printf("\n%d X: ", a+1);
    scanf("%d", &pm[a].x);
    printf("\n%d Y: ", a+1);
    scanf("%d", &pm[a].y);
    printf("\n%d Z: ", a+1);
    scanf("%d", &pm[a].z);
    xx=pm[a].x*pm[a].x;
    yy=pm[a].y*pm[a].y;
    zz=pm[a].z*pm[a].z;
    xyz=xx+yy+zz;
    printf("\n",a+1);
    pm[a].result=sqrt (xyz);
  }
}


double to_Sort (koord pm[], int n, koord b){
	int a, k;
	for (k=0; k<n-1; k++){
		for (a=0; a<n-1; a++){
			if(pm[a].result>pm[a+1].result){
				b=pm[a];
				pm[a]=pm[a+1];
				pm[a+1]=b;
			}else{
				continue;
			}
		}
	}
}

double to_Max (koord pm[], int n){
	int a=0;
	double max;
	if (pm[a].result<pm[a+1].result){
		max=pm[a+1].result;
	}else{
		max=pm[a].result;
	}
	for (a=2; a<n; a++){
		if (max<pm[a].result){
			max=pm[a].result;
		}else{
			max=max;
		}
	}
}

double to_Min (koord pm[], int n){
	int a;
	double min;
	if(pm[0].result>pm[1].result){
		min=pm[1].result;
	}else{
		min=pm[0].result;
	}
	for (a=2; a<n; a++){
		if(min>pm[a].result){
			min=pm[a].result;
		}else{
			min=min;
		}
	}
}



int main(void){
  int M;
  printf("VVedit kilkist tochok:");
  scanf("%d", &M);
  koord mas[M], *pst, b;
  to_vvid(mas, M);
  to_Sort(mas, M, b);
  for(pst=mas; pst < (mas + M); pst++){
    printf("X: %d   Y: %d   Z: %d   Vidstan: %.02f\n",pst->x, pst->y, pst->z, pst->result);
  }
  printf("Max Viddal: %.02f\n", to_Max(mas, M));
  printf("Min Viddal: %.02f\n", to_Min(mas, M));
  return 0;
}
