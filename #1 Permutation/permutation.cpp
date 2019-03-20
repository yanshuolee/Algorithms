//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "permutation.h"

int length, count;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void permute(String s, int start)
{
	int tmp;
	if (start==length) {
		Form1->Memo1->Lines->Add("["+IntToStr(++count)+"]: "+s);
	}else{
		for (int i = start; i <= length; i++) {
			tmp=s[start]; s[start]=s[i]; s[i]=tmp;
			permute(s, start+1);
			tmp=s[start]; s[start]=s[i]; s[i]=tmp;
		}
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	String text;
	count = 0;
	text = Edit1->Text;
	length = text.Length();
	permute(text, 1);
    Memo1->Lines->Add("\n");
}
//---------------------------------------------------------------------------
