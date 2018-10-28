//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "sorting.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int *data;
int number;
String output;
clock_t merge_total;
const int MAX_STACK = 10000;
int stack[MAX_STACK];
int top;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void swap(int *x, int*y)
{
	int tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

int min(int x, int y)
{
	if(x>y) return y;
	else return x;
}

void selection(void)
{
	int min;
	int *tmp_data;
	clock_t start, end;
	tmp_data = new int[number];
	std::copy(data, data+number, tmp_data);
	output = "";

	start = clock();
	for(int i=0;i<number-1;i++)
	{
		min = i;
		for(int j=i+1;j<number;j++)
		{
			if(tmp_data[j]<tmp_data[min]) min = j;
		}
		swap(&tmp_data[i], &tmp_data[min]);
		output += IntToStr(tmp_data[i])+", ";
	}
	output += IntToStr(tmp_data[number-1])+", ";
	end = clock();

	Form1->Memo1->Lines->Add("<Selection Sort>");
	Form1->Memo1->Lines->Add("Time elapsed: "+FloatToStr((float)(end-start)/CLK_TCK));
	Form1->Memo1->Lines->Add("--------------------------------------");
	if(Form1->CheckBox13->Checked == true)
	{
		Form1->Memo1->Lines->Add(output);
	}
	Form1->Memo1->Lines->Add("");

	delete [] tmp_data;
}

void insertion(void)
{
	int *tmp_data, j, target;
	clock_t start, end;
	tmp_data = new int[number];
	std::copy(data, data+number, tmp_data);
	output = "";

	start = clock();
	for(int i=1;i<number;i++)
	{
		target = tmp_data[i];
		j = i;
		while((tmp_data[j-1]>target)&&(j>0))
		{
			tmp_data[j] = tmp_data[j-1];
			j--;
		}
		tmp_data[j] = target;
	}
	end = clock();

	for(int i=0;i<number;i++) output += IntToStr(tmp_data[i])+", ";

	Form1->Memo1->Lines->Add("<Insertion Sort>");
	Form1->Memo1->Lines->Add("Time elapsed: "+FloatToStr((float)(end-start)/CLK_TCK));
	Form1->Memo1->Lines->Add("--------------------------------------");
	if(Form1->CheckBox13->Checked == true)
	{
		Form1->Memo1->Lines->Add(output);
	}
	Form1->Memo1->Lines->Add("");

	delete [] tmp_data;

}

void bubble(void)
{
	int *tmp_data;
	clock_t start, end;
	tmp_data = new int[number];
	std::copy(data, data+number, tmp_data);
	output = "";

	start = clock();
	for(int i=number-1;i>0;i--)
	{
		for(int j=1;j<=i;j++)
		{
			if(tmp_data[j]<tmp_data[j-1]) swap(&tmp_data[j], &tmp_data[j-1]);
        }
	}
	end = clock();

	for(int i=0;i<number;i++) output += IntToStr(tmp_data[i])+", ";
	Form1->Memo1->Lines->Add("<Bubble Sort>");
	Form1->Memo1->Lines->Add("Time elapsed: "+FloatToStr((float)(end-start)/CLK_TCK));
	Form1->Memo1->Lines->Add("--------------------------------------");
	if(Form1->CheckBox13->Checked == true)
	{
		Form1->Memo1->Lines->Add(output);
	}
	Form1->Memo1->Lines->Add("");

	delete [] tmp_data;
}

void update(int unsorted_arr[], int root, int node)
{
	int small;
	while(root<=node/2)
	{
		small = unsorted_arr[2*root]>unsorted_arr[2*root+1] ? 2*root+1 : 2*root;
		if(unsorted_arr[small] > unsorted_arr[root]) break; // Attension
		swap(&unsorted_arr[small], &unsorted_arr[root]);
		root = small; // Attention
	}
}

void heap(void)
{
	int *tmp_data;
	clock_t start, end;
	tmp_data = new int[number+1];
	std::copy(data, data+number, tmp_data+1);
	output = "";

	start = clock();
	// Create heap
	for(int i=number/2;i>=1;i--)
		update(tmp_data, i, number);
	// Delete heap
	for(int i=number;i>=1;i--)
	{
		output += IntToStr(tmp_data[1])+", ";
		tmp_data[1] = tmp_data[i];
		update(tmp_data, 1, i-1); // Attention
	}
	end = clock();

	Form1->Memo1->Lines->Add("<Heap Sort>");
	Form1->Memo1->Lines->Add("Time elapsed: "+FloatToStr((float)(end-start)/CLK_TCK));
	Form1->Memo1->Lines->Add("--------------------------------------");
	if(Form1->CheckBox13->Checked == true)
	{
		Form1->Memo1->Lines->Add(output);
	}
	Form1->Memo1->Lines->Add("");

	delete [] tmp_data;

}

void merge(int c[], int k, int a[], int a1, int a2, int b[], int b1, int b2)
{
	clock_t start, end;

	start = clock();
	int oriK = k;
	while((a1<=a2)&&(b1<=b2))
	{
		if(a[a1]>=b[b1])
		{
			c[k++] = b[b1];
			b1++;
		}else{
			c[k++] = a[a1];
			a1++;
		}
	}
	while(a1<=a2) c[k++] = a[a1++];
	while(b1<=b2) c[k++] = b[b1++];

	for(int i=oriK;i<k;i++) a[i] = c[i];
	end = clock();
	merge_total = end-start;
}

void merge_sort_recursive(int c[], int a[], int left, int right)
{
	int middle;
	if(left<right)
	{
		middle = (left+right)/2;
		merge_sort_recursive(c, a, left, middle);
		merge_sort_recursive(c, a, middle+1, right);
		merge(c, left, a, left, middle, a, middle+1, right);

	}


}

void main_mergesort_recursive()
{
	int *tmp_data, *out_data;
	clock_t start, end;
	merge_total=0;
	tmp_data = new int[number];
	out_data = new int[number];
	std::copy(data, data+number, tmp_data);
	output = "";

	start = clock();
	merge_sort_recursive(out_data, tmp_data, 0, number-1);
	end = clock();

	for(int i=0;i<number;i++) output += IntToStr(tmp_data[i])+", ";
	Form1->Memo1->Lines->Add("<Recursive Merge Sort>");
	Form1->Memo1->Lines->Add("Time elapsed(Total): "+FloatToStr((float)(end-start)/CLK_TCK));
	Form1->Memo1->Lines->Add("Time elapsed(Merge operation): "+FloatToStr((float)merge_total/CLK_TCK));
	Form1->Memo1->Lines->Add("--------------------------------------");
	if(Form1->CheckBox13->Checked == true)
	{
		Form1->Memo1->Lines->Add(output);
	}
	Form1->Memo1->Lines->Add("");

	delete [] tmp_data;
}

void mergesort_iteration()
{
	int *tmp_data, *out_data;
	clock_t start, end;
	merge_total=0;
	tmp_data = new int[number];
	out_data = new int[number];
	std::copy(data, data+number, tmp_data);
	output = "";

	start = clock();
	int len = 1, i;
	while(len < number)
	{
		i=0;
		while(i<number-len)
		{
			merge(out_data, i, tmp_data, i, i+len-1, tmp_data, i+len, min(i+2*len-1, number-1));
			i = i + 2*len;
		}
		len *= 2;
	}
	end = clock();

	for(int j=0;j<number;j++) output += IntToStr(tmp_data[j])+", ";
	Form1->Memo1->Lines->Add("<Iternation Merge Sort>");
	Form1->Memo1->Lines->Add("Time elapsed(Total): "+FloatToStr((float)(end-start)/CLK_TCK));
	Form1->Memo1->Lines->Add("Time elapsed(Merge operation): "+FloatToStr((float)merge_total/CLK_TCK));
	Form1->Memo1->Lines->Add("--------------------------------------");
	if(Form1->CheckBox13->Checked == true)
	{
		Form1->Memo1->Lines->Add(output);
	}
	Form1->Memo1->Lines->Add("");

	delete [] tmp_data;
	delete [] out_data;

}

int getDigit(int NUM, int DIGIT)
{
	int N, ans;
	N = NUM / DIGIT;
	ans = N % 10;
	return ans;
}

void radix(void)
{
	int radix;
	float max=0.0;
	int *tmp_data, *tmp;
	clock_t start, end;
	tmp_data = new int[number];
	tmp = new int[number];
	int count[10], index[10];
	std::copy(data, data+number, tmp_data);
	output = "";

	start = clock();
	for(int i=0;i<number;i++)
	{
		if(tmp_data[i] > max)
			max = tmp_data[i];
	}
	radix = log10(max)+1;

	int digit_index = 1;
	for(int j=1;j<=radix;j++)
	{
		// Init all count[], index[]
		for(int i=0;i<10;i++)
		{
			count[i] = 0;
			index[i] = 0;
        }

		int digit;

		for(int i=0;i<number;i++)
		{
			digit = getDigit(tmp_data[i], digit_index);
			count[digit]++;
		}

		for(int i=0;i<9;i++)
		{
			index[i+1] = index[i] + count[i];
        }

		for(int i=0;i<number;i++)
		{
			digit = getDigit(tmp_data[i], digit_index);
			tmp[index[digit]] = tmp_data[i];
			index[digit]++;
        }

		for(int i=0;i<number;i++)
			tmp_data[i] = tmp[i];

		digit_index *= 10;
	}
	end = clock();

	for(int j=0;j<number;j++) output += IntToStr(tmp_data[j])+", ";
	Form1->Memo1->Lines->Add("<Radix Sort>");
	Form1->Memo1->Lines->Add("Time elapsed(Total): "+FloatToStr((float)(end-start)/CLK_TCK));
	Form1->Memo1->Lines->Add("--------------------------------------");
	if(Form1->CheckBox13->Checked == true)
	{
		Form1->Memo1->Lines->Add(output);
	}
	Form1->Memo1->Lines->Add("");

	delete [] tmp_data;
	delete [] tmp, count, index;

}

void quicksort_recursion(int data[], int left, int right)
{
	int i, j, target;
	if(left < right)
	{
		i = left + 1;
		j = right;
		target = data[left];
		do{
			while(target > data[i] && i<=j) i++;
			while(target <= data[j] && i<=j) j--;
			if(i < j) swap(&data[i], &data[j]);
		}while(i<j);

		if(left < j) swap(&data[left], &data[j]);
		quicksort_recursion(data, left, j-1);
		quicksort_recursion(data, j+1, right);
	}
}

void Q_recursion(void)
{
	int *tmp_data, target;
	clock_t start, end;
	tmp_data = new int[number];
	std::copy(data, data+number, tmp_data);
	output = "";

	start = clock();
	quicksort_recursion(tmp_data, 0, number-1);
	end = clock();

	for(int j=0;j<number;j++) output += IntToStr(tmp_data[j])+", ";
	Form1->Memo1->Lines->Add("<Recursion Quick Sort>");
	Form1->Memo1->Lines->Add("Time elapsed(Total): "+FloatToStr((float)(end-start)/CLK_TCK));
	Form1->Memo1->Lines->Add("--------------------------------------");
	if(Form1->CheckBox13->Checked == true)
	{
		Form1->Memo1->Lines->Add(output);
	}
	Form1->Memo1->Lines->Add("");

	delete [] tmp_data;

}

int IsFull()
{
	if(top == MAX_STACK-1) return 1;
	else return 0;
}
int IsEmpty()
{
	if(top == -1) return 1;
	else return 0;
}
void push(int x)
{
	if(IsFull())
		Form1->Memo1->Lines->Add("Stack Full!");
	else
		stack[++top] = x;
}
int pop()
{

	if(IsEmpty())
	{
		Form1->Memo1->Lines->Add("Stack Empty!");
		return -1;
	}
	else
		return stack[top--];
}

void Q_iteration(void)
{
	int *tmp_data;
	clock_t start, end;
	tmp_data = new int[number];
	std::copy(data, data+number, tmp_data);
	output = "";
	int left, right, target, i, j;
	top = -1;

	start = clock();
	left = 0;
	right = number-1;
	push(left);
	push(right);

	while(top > -1)
	{
		right = pop();
		left = pop();
		target = tmp_data[left];
		i = left+1;
		j = right;
		do{
			while(target > tmp_data[i] && i <= j) i++;
			while(target <= tmp_data[j] && i <= j) j--;
			if(i < j) swap(&tmp_data[i], &tmp_data[j]);
		}while(i<j);
		if(left < j) swap(&tmp_data[left], &tmp_data[j]);

		if(j+1 < right)
		{
			push(j+1);
			push(right);
		}
		if(left < j-1)
		{
			push(left);
			push(j-1);
		}
	}
	end = clock();

    for(int j=0;j<number;j++) output += IntToStr(tmp_data[j])+", ";
	Form1->Memo1->Lines->Add("<Iternation Quick Sort>");
	Form1->Memo1->Lines->Add("Time elapsed(Total): "+FloatToStr((float)(end-start)/CLK_TCK));
	Form1->Memo1->Lines->Add("--------------------------------------");
	if(Form1->CheckBox13->Checked == true)
	{
		Form1->Memo1->Lines->Add(output);
	}
	Form1->Memo1->Lines->Add("");

	delete [] tmp_data, stack;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::GenerateClick(TObject *Sender)
{
	delete [] data;
	int rng;
	number = StrToInt(num->Text);
	rng = StrToInt(range->Text);
	data = new int[number];

	output = "";
	for(int i=0;i<number;i++)
	{
		data[i] = rand()%(rng+1);
		output += IntToStr(data[i])+", ";
	}
	if(CheckBox8->Checked == true)
	{
		Memo1->Lines->Add("<Data>");
		Memo1->Lines->Add(output);
		Memo1->Lines->Add("");
	}else{
		Memo1->Lines->Add("Data generated!");
		Memo1->Lines->Add("");
	}


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if(CheckBox2->Checked == true) selection();
	else if(CheckBox3->Checked == true) insertion();
	else if(CheckBox1->Checked == true) bubble();
	else if(CheckBox5->Checked == true)
	{
		if(CheckBox11->Checked == true) Q_recursion();
		else if(CheckBox12->Checked == true) Q_iteration();
		else Memo1->Lines->Add("Please select recursion or iteration version.");
	}
	else if(CheckBox6->Checked == true) heap();
	else if(CheckBox7->Checked == true) radix();
	else if(CheckBox4->Checked == true)
	{
		if(CheckBox9->Checked == true) main_mergesort_recursive();
		else if(CheckBox10->Checked == true) mergesort_iteration();
		else Memo1->Lines->Add("Please select recursion or iteration version.");
	}
	else{
		Memo1->Lines->Add("Please select one sorting methods.");
        Memo1->Lines->Add("");
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
	if(CheckBox1->Checked == true)
	{
		CheckBox2->Checked = false;
		CheckBox3->Checked = false;
		CheckBox4->Checked = false;
		CheckBox5->Checked = false;
		CheckBox6->Checked = false;
		CheckBox7->Checked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
	if(CheckBox2->Checked == true)
	{
		CheckBox1->Checked = false;
		CheckBox3->Checked = false;
		CheckBox4->Checked = false;
		CheckBox5->Checked = false;
		CheckBox6->Checked = false;
		CheckBox7->Checked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox3Click(TObject *Sender)
{
	if(CheckBox3->Checked == true)
	{
		CheckBox1->Checked = false;
		CheckBox2->Checked = false;
		CheckBox4->Checked = false;
		CheckBox5->Checked = false;
		CheckBox6->Checked = false;
		CheckBox7->Checked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
	if(CheckBox4->Checked == true)
	{
		CheckBox1->Checked = false;
		CheckBox2->Checked = false;
		CheckBox3->Checked = false;
		CheckBox5->Checked = false;
		CheckBox6->Checked = false;
		CheckBox7->Checked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox5Click(TObject *Sender)
{
	if(CheckBox5->Checked == true)
	{
		CheckBox1->Checked = false;
		CheckBox2->Checked = false;
		CheckBox3->Checked = false;
		CheckBox4->Checked = false;
		CheckBox6->Checked = false;
		CheckBox7->Checked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox6Click(TObject *Sender)
{
	if(CheckBox6->Checked == true)
	{
		CheckBox1->Checked = false;
		CheckBox2->Checked = false;
		CheckBox3->Checked = false;
		CheckBox4->Checked = false;
		CheckBox5->Checked = false;
		CheckBox7->Checked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox7Click(TObject *Sender)
{
	if(CheckBox7->Checked == true)
	{
		CheckBox1->Checked = false;
		CheckBox2->Checked = false;
		CheckBox3->Checked = false;
		CheckBox4->Checked = false;
		CheckBox5->Checked = false;
		CheckBox6->Checked = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox9Click(TObject *Sender)
{
	if(CheckBox9->Checked == true)  CheckBox10->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox10Click(TObject *Sender)
{
	if(CheckBox10->Checked == true)  CheckBox9->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox11Click(TObject *Sender)
{
	if(CheckBox11->Checked == true)  CheckBox12->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox12Click(TObject *Sender)
{
    if(CheckBox12->Checked == true)  CheckBox11->Checked = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int t, rng;
	t = StrToInt(times->Text);
	number = 50000; // 5000
	rng = StrToInt(range->Text);


	for(int i=1;i<=t;i++)
	{
		data = new int[number];
		output = "";
		for(int j=0;j<number;j++)
		{
			data[j] = rand()%(rng+1);
			output += IntToStr(data[j])+", ";
		}
		Memo1->Lines->Add(IntToStr(i));
		Memo1->Lines->Add("Data generated!");
		Memo1->Lines->Add("");

		bubble();
		selection();
		insertion();
		heap();
		radix();
		main_mergesort_recursive();
		mergesort_iteration();
		Q_recursion();
		Q_iteration();

		number += 1000;
		delete [] data;
	}
}
//---------------------------------------------------------------------------

