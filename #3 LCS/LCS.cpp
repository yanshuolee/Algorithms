//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "LCS.h"
int L [200][200];
int M [200][200];
#define MAX(a,b)((a>b)?a:b)
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
String LCS(String A, String B)
{
	int i, j;
	int m = A.Length();
	int n = B.Length();
	for (i = 0; i <= m; i++) L[i][0] = 0;
	for (j = 1; j <= n; j++) L[0][j] = 0;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (A[i]==B[j]){
				L[i][j] = L[i-1][j-1]+1;
				M[i][j] = 0;
            }
			else{
				L[i][j] = MAX(L[i-1][j], L[i][j-1]);
				M[i][j] = (L[i-1][j] > L[i][j-1]) ? 1 : 2;
			}
		}
	}
	Form1->StringGrid1->RowCount = m+1;
	Form1->StringGrid1->ColCount = n+1;
    for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			Form1->StringGrid1->Cells[j][i] = L[i][j];
		}
	}

	i  = m;
	j = n;
	String lcs = "", x;
	while (i>0 && j>0)
	{
		if(M[i][j] == 0)
		{
			x = A[i];
			lcs = x + lcs;
			i--; j--;
		}
		else if (M[i][j] == 1) i--;
		else j--;
	}

	return lcs;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	String A = Edit1->Text;
	String B = Edit2->Text;
	Memo1->Lines->Add(LCS(A, B));
}
//---------------------------------------------------------------------------
