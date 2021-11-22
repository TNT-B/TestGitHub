#include <iostream>

using namespace std;

void setArray(int a[], int& n);
void printArray(int a[], int n);
int sumArray(int a[], int n);
int findMin(int a[], int n);
bool checkPrime(int n);
int countNumberofPrime(int a[], int n);
bool isAscendingOrder(int a[], int n);
int countOccurrences(int a[], int n);
void deleteItems(int a[], int &n, int x);
void deleteItemsFromIndex(int a[], int &n);


{
	int a[1000], n;

	cout << "Nhap so luong phan tu: ";
	cin >> n;

	setArray(a, n);
	printArray(a, n);

	//cout << "Tong cua cac phan tu trong mang la " << sumArray(a, n) << endl;

	//cout << "Phan tu nho nhat trong mang la " << findMin(a, n) << endl;

	//cout << "Mang nay co " << countNumberofPrime(a, n) << " so nguyen to" << endl;

	//if (isAscendingOrder(a, n)) cout << "Mang nay tang dan" << endl;
	//else cout << "Mang nay khong tang dan" << endl;

	//cout << "So lan xuat hien cua gia tri tren la: " << countOccurrences(a, n) << " lan " << endl;

	int x;
	cout << "Phan tu ban muon xoa la: ";
	cin >> x;
	deleteItems(a, n, x);
	//printArray(a, n);

	//deleteItemsFromIndex(a, n);
	printArray(a, n);
    
	return 0;
}

void setArray(int a[], int& n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu: ";
		cin >> a[i];
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}

int sumArray(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = sum + a[i];
	}
	return sum;
}

int findMin(int a[], int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (min > a[i]) min = a[i];
	}
	return min;
}

bool checkPrime(int n)
{	
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int countNumberofPrime(int a[], int n)
{	
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (checkPrime(a[i])) count++;
	}
	return count;
}

bool isAscendingOrder(int a[], int n)
{
	for (int i = 0; i < (n-1); i++)
	{
		if (a[i + 1] < a[i])
		{
			return false;
		}
	}
	return true;
}

int countOccurrences(int a[], int n)
{
	int x, count = 0;
	cout << "Nhap gia tri muon dem so lan xuat hien: ";
	cin >> x;

	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			count++;
		}
	}
	return count;
}

void deleteItems(int a[], int &n, int x)//dang sai
{
	int tmp = n;
	for (int i = 0; i < tmp; i++)
	{
		if (a[i] == x)
		{
			for (int j = i; j < tmp; j++)
			{	
				a[j] = a[j + 1];
			}
			n--;
		}
	}
}

void deleteItemsFromIndex(int a[], int &n)
{
	int pos, amt;

	cout << "Nhap vi tri phan tu ban muon bat dau xoa: ";
	cin >> pos;
	cout << "Nhap so phan tu muon xoa: ";
	cin >> amt;

	if (amt == 1)
	{
		for (int i = pos; i < n; i++)
		{
			a[i] = a[i + 1];
		}
		n--;
		return;
	}

	for (int i = 0; i < n; i++)
	{	
		if (i == pos)
		{
			for (int j = pos; j < n; j++)
			{
				a[j] = a[j + amt];
				n--;
			}
		}
	}
}
