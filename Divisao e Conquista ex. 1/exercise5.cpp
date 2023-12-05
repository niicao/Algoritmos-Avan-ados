//Disciplina: Algoritmos Avançados - Exercicio 5
//Nicholas Yudi Kurita Ikai - 13671852
#include <stdio.h>
#include <stdbool.h>
#include <bits/stdc++.h>

using namespace std;

//Funcao responsavel por fundir os vetores e somar a quantidade de inversões na fusão

long long int mergeArrays(long long int arr[], long long int temp[], long long int left, long long int mid,
		long long int right){

	int i, j, k;
	long long int inv_count = 0;

	i = left;
	j = mid;
	k = left;

	while ((i <= mid - 1) && (j <= right)){
		if(arr[i] <= arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];

			inv_count = inv_count + (mid - i);
		}
	}


	while (i <= mid - 1)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];

	for(i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

//Função que ordena o vetor de entrada e retorna o número de inverões no vetor
long long int invCount(long long int arr[], long long int temp[], long long int left, long long int right){

	long long int mid;
    long long int inv_count = 0;
	if (right > left) {

		mid = (right + left) / 2;

		inv_count += invCount(arr, temp, left, mid);
		inv_count += invCount(arr, temp, mid + 1, right);

		inv_count += mergeArrays(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

long long int mergeSort(long long int arr[], long long int array_size)
{
	long long int temp[array_size];
	return invCount(arr, temp, 0, array_size - 1);
}


int main()
{
	long long int array_size;
    cin >> array_size;

    long long int array[array_size];
    for(int i = 0; i < array_size; i++){
        cin >> array[i];
    }

    cout << mergeSort(array, array_size) << "\n";

	return 0;
}

