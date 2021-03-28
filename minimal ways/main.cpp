#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <cstring>
#define max 1000000000
using namespace std;

/*30000  399868
* 30000  199955
* 30000  29999
* 979  271592
*/

unsigned int minimumDist(unsigned int dist[], bool Tset[],unsigned int number)
{
	unsigned int min = INT_MAX, index;

	for (unsigned int i = 0; i < number; i++)
	{
		if (Tset[i] == false && dist[i] <= min)
		{
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void Dijkstra(short** matrix, unsigned int src,unsigned int number)
{
	unsigned int* dist = new unsigned int [number];                           
	bool* Tset = new bool [number];


	for (unsigned int i = 0; i < number; i++)
	{
		dist[i] = INT_MAX;
		Tset[i] = false;
	}

	dist[src] = 0;      

	for (unsigned int i = 0; i < number; i++)
	{
		unsigned int m = minimumDist(dist, Tset,number); // vertex not yet included.
		Tset[m] = true;// m with minimum distance included in Tset.
		for (unsigned int i = 0; i < number; i++)
		{
			// Updating the minimum distance for the particular node.
			if (!Tset[i] && matrix[m][i] && dist[m] != INT_MAX && dist[m] + matrix[m][i] < dist[i])
				dist[i] = dist[m] + matrix[m][i];
		}
	}
	for (unsigned int i = 0; i < number; i++) {
		free(matrix[i]);
	}
	free(matrix);
	ofstream file_for_writing("C:\\Tests\\path.out");
	for (unsigned int i = 0; i < number; i++) {
		file_for_writing << dist[i] << " ";
	}
	file_for_writing.close(); 
}


unsigned int main() 
{
	ifstream file_for_reading("C:\\Tests\\path.in");
	short number_of_vertexes;
	int edge;
	file_for_reading >> number_of_vertexes >> edge;
	if (number_of_vertexes < 1 || number_of_vertexes > 30000 || edge < 0 || edge>400000) { cout << "Correct your vallues"; exit(1); };
	short i;
	short** matrix = new short* [number_of_vertexes];
	for (i = 0; i < number_of_vertexes; i++)
		matrix[i] = new short[number_of_vertexes];
	unsigned int first_vertex, second_vertex, edge_size;
	int tmp = 0;
	while (tmp != edge) {
		int first_vertex, second_vertex, edge_size;
		file_for_reading >> first_vertex >> second_vertex >> edge_size;
		matrix[first_vertex - 1][second_vertex - 1] = matrix[second_vertex - 1][first_vertex - 1] = edge_size;
		tmp++;
	}
	file_for_reading.close();
	Dijkstra(matrix, 0, number_of_vertexes);
}
