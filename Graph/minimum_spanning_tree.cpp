//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "minimum_spanning_tree.h"
#include <time.h>
int** GRAPH;
int** EDGE;
int N_EDGES;
int *used;
int *mask;
int *mst;
int NUM_OF_CYCLE;
int MST_INDEX;
int NUMBER_OF_VECTOR;
int MAX = 99999;
clock_t t1, t2;
clock_t t11, t12, t13, t14, t15, t16;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

int select_smallest_edge_using_comparison()
{
	t13 = clock();
	int min =0;
	for(int i=1;i<=N_EDGES;i++)
	{
		if((EDGE[min][2]>EDGE[i][2]) && (used[i]==0)) min = i;
	}
	used[min] = 1;
	t14 = clock();
	return min;
}

void detect_cycling(int min)
{
	int start, end, small, large;
	start = EDGE[min][0];
	end = EDGE[min][1];
	t15 = clock();
	if(mask[start]!=mask[end])
	{
		mst[MST_INDEX++] = min;
		// 大號變小號
		small = (mask[start]<mask[end])? mask[start]:mask[end];
		large = (mask[start]<mask[end])? mask[end]:mask[start];
		// Union Iteration
		for(int i=0;i<NUMBER_OF_VECTOR;i++)
		{
			if(mask[i]==large) mask[i] = small;
		}
	}else{
		NUM_OF_CYCLE++;
	}
	t16 = clock();
}


//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	t1 = clock();
	NUMBER_OF_VECTOR = StrToInt(num_of_vector->Text);
	int RANGE = StrToInt(rng_of_weight->Text);
	int THRESHOLD = StrToInt(threshold->Text);


	// Dynamically allocate adjacent matrix array
	GRAPH = new int*[NUMBER_OF_VECTOR];
	for(int i=0;i<NUMBER_OF_VECTOR;i++)
	{
		GRAPH[i] = new int[NUMBER_OF_VECTOR];
	}

	// Generate Matrix
	for(int row=0;row<NUMBER_OF_VECTOR;row++)
	{
		for(int col=row;col<NUMBER_OF_VECTOR;col++)
		{
			if(col==row) GRAPH[row][col]=MAX;
			else{
				int rnd = rand()%(RANGE+1)+1;
                if(rnd>THRESHOLD) rnd = MAX;
				GRAPH[row][col] = rnd;
				GRAPH[col][row] = rnd;
			}

		}
	}

	// Set up String Grid
	StringGrid1->RowCount = NUMBER_OF_VECTOR;
	StringGrid1->ColCount = NUMBER_OF_VECTOR;

	// Draw Matrix to String Grid
	for(int row=0;row<NUMBER_OF_VECTOR;row++)
	{
		for(int col=0;col<NUMBER_OF_VECTOR;col++)
		{
			StringGrid1->Cells[col][row] = IntToStr(GRAPH[row][col]);
		}
	}

	// Dynamically allocate adjacent list array
	N_EDGES = 0;

	for(int row=0;row<NUMBER_OF_VECTOR;row++)
	{
		for(int col=row+1;col<NUMBER_OF_VECTOR;col++)
		{
			if(GRAPH[row][col]<MAX) N_EDGES++;
		}
	}

	EDGE = new int*[N_EDGES+1]; // starting from 1
	for(int i=0;i<=N_EDGES;i++)
	{
		EDGE[i] = new int[3];
	}

	used = new int[N_EDGES+1];
	mask = new int[NUMBER_OF_VECTOR];
	mst = new int[NUMBER_OF_VECTOR];

	int edge_index = 0;
	for(int row=0;row<NUMBER_OF_VECTOR;row++)
	{
		for(int col=row+1;col<NUMBER_OF_VECTOR;col++)
		{
			if(GRAPH[row][col]<MAX)
			{
				EDGE[++edge_index][0] = row;
				EDGE[edge_index][1] = col;
				EDGE[edge_index][2] = GRAPH[row][col];
			}
		}
	}
	EDGE[0][2] = MAX; // 小吾小用

	// Initialise Used, Mask and mst
	for(int i=1;i<N_EDGES;i++) used[i] = 0;
	for(int i=0;i<NUMBER_OF_VECTOR;i++)
	{
		mask[i] = i;
		mst[i] = -1;
	}

	// Draw List to Sting Grid
	StringGrid2->RowCount = N_EDGES;
	StringGrid2->ColCount = 3;
	for(int row=1;row<=N_EDGES;row++)
	{
		for(int col=0;col<3;col++)
		{
			StringGrid2->Cells[col][row] = EDGE[row][col];
        }
    }

	t2 = clock();

}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button3Click(TObject *Sender)
{
	MST_INDEX = 0;
	NUM_OF_CYCLE = 0;
	int min;
	clock_t t_min = 0, t_cycle = 0;

	t11 = clock();
	while(MST_INDEX < NUMBER_OF_VECTOR-1 && NUM_OF_CYCLE+MST_INDEX<=N_EDGES)
	{
		min = select_smallest_edge_using_comparison();
		t_min += t14-t13;
		detect_cycling(min);
		t_cycle += t16-t15;
	}
	if(MST_INDEX < NUMBER_OF_VECTOR-1)
		Memo1->Lines->Add("No Minimum Spanning Tree in This Case!");
	else{
		int mst_len = 0;
		// Add all costs
		for(int i=0;i<MST_INDEX;i++)
		{
			mst_len += EDGE[mst[i]][2];
		}
		if(CheckBox1->Checked == True)
		{
			for(int i=0;i<MST_INDEX;i++)
			{
				Memo1->Lines->Add("Edge "+IntToStr(i)+": ("+IntToStr(EDGE[mst[i]][0])+","+IntToStr(EDGE[mst[i]][1])+") = "+IntToStr(EDGE[mst[i]][2]));
			}
			Memo1->Lines->Add("Cycle edge: "+IntToStr(NUM_OF_CYCLE));
		}


	}
	t12 = clock();

	Memo1->Lines->Add("<Kruskal Time Detail>");
	Memo1->Lines->Add("Creating graph: "+FloatToStr((float)(t2-t1)/CLK_TCK)+" sec.");
	Memo1->Lines->Add("Finding minimun edge(comparison): "+FloatToStr((float)t_min/CLK_TCK)+" sec.");
	Memo1->Lines->Add("Cycle detection: "+FloatToStr((float)t_cycle/CLK_TCK)+" sec.");
	Memo1->Lines->Add("Kruskal Algo(minimun+cycle): "+FloatToStr((float)(t12-t11)/CLK_TCK)+" sec.");
	Memo1->Lines->Add("");

	// Release All Resources
	for(int i=0;i<=N_EDGES;i++) delete EDGE[i];
	delete EDGE;
	delete used;
	delete mst;
	delete mask;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int *X, *Y, *c1, *c2;
	int x, x_count, min, tmp_x;
	clock_t T_start, T_end;

	T_start = clock();
	X = new int[NUMBER_OF_VECTOR];
	Y = new int[NUMBER_OF_VECTOR];
	c1 = new int[NUMBER_OF_VECTOR];
	c2 = new int[NUMBER_OF_VECTOR];

	// Select random vector
	x = rand()%NUMBER_OF_VECTOR;
	int sp = x;
	// Initialisation
	for(int i=0;i<NUMBER_OF_VECTOR;i++)
	{
		c1[i] = x;
		c2[i] = MAX;
		X[i] = 0;
		Y[i] = 1;
	}

	// Update after selection
	X[x] = 1;
	Y[x] = 0;
	x_count = 1;
	while(x_count < NUMBER_OF_VECTOR)
	{
		// Update distance
		for(int y=0;y<NUMBER_OF_VECTOR;y++)
		{
			if((Y[y] == 1)&&(GRAPH[x][y]<c2[y]))
			{
				c1[y] = x;
				c2[y] = GRAPH[x][y];
			}
		}

		min = 0;
		// Find shortest path
		for(int y=0;y<NUMBER_OF_VECTOR;y++)
		{
			if(c2[y]<c2[min]) min = y;
		}

		// No MST
		if(c2[min] == MAX) break;

		//
		tmp_x = c1[min];// min點靠誰連出去的
		c2[min] = MAX;
		X[min] = 1;
		Y[min] = 0;
		x_count++;
		x = min;
	}
	T_end = clock();

	// Print ans
	if(x_count < NUMBER_OF_VECTOR)
		Memo1->Lines->Add("No Minumin Spaaning Tree!");
	else
	{
		Memo1->Lines->Add("Vertex starting from: " + IntToStr(sp));
		for(int i=0;i<NUMBER_OF_VECTOR;i++)
		{
			int j = i+1;
			if(j<NUMBER_OF_VECTOR)
				if(CheckBox1->Checked == True)
				{
				   Memo1->Lines->Add("Edge " + IntToStr(i) + ": (" + IntToStr(c1[j]) + ","+IntToStr(j) + ") = " + IntToStr(GRAPH[c1[j]][j]));
				}



		}
		Memo1->Lines->Add("<Prim Time Detail>");
		Memo1->Lines->Add("Time elapsed: " + FloatToStr((float)(T_end-T_start)/CLK_TCK)+" sec.");
		Memo1->Lines->Add("");
	}
	delete X;
	delete Y;
	delete c1;
	delete c2;
}
//---------------------------------------------------------------------------



