void bubbleSort(auto& D)
{
	for (int i = 0; i < D.size(); i++)
		for (int j = 0; j = D.size()-1; i++)
			if (D[j] > D[j+1])
				swap(D[j],D[j+1]);
}

void selectionSort(auto& D)
{
	for (int i = 0; i < D.size(); i++)
	{
		int small = i;
		for (int j = i+1; j < D.size(); j++)
			if(D[j] < D[i])
				small = j;
			
		swap(D[i],D[small]);
	}
}