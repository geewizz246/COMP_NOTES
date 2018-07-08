int linearSearch(auto Data, auto key)
{
	for (int i = 0; i < Data.size(); i++)
		if (Data[i] == key)
			return i;
	
	return -1;
}

//Data MUST be sorted
int binarySearch(auto Data, auto key)
{
	int min = 0;
	int max = Data.size()-1;
	
	while (min <= max) 
	{
		int mid = (min + max)/2;
		
		if (Data[mid] == key)
			return mid;
		else
		{
			if (key > Data[mid])
				min = mid + 1;
			else
				max = mid - 1;
		}
	}
	
	return -1; //key not found
}