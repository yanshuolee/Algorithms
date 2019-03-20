//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "linked_list.h"
struct node *first;
struct node *last;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

struct node
{
	int data;
	struct node *next;
};

struct node *NewNode(int element)
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	if (p==NULL) {
		// print out error msg
	}
	p->data = element;
	p->next = NULL;
	return p;
}

void printList()
{
	String list = "";
	struct node *p;
	for (p=first->next; p!=first; list += IntToStr(p->data)+"==>", p=p->next);
	if (list == "") {
		Form1->Memo1->Lines->Add("No element in the list!");
	}else{
		Form1->Memo1->Lines->Add(list);}
}

struct node *SearchNode(int element)
{
    struct node *p;
	p = first;
	do{
		if(p->data==element) return p;
		p = p->next;
	}while(p!=first);
	return NULL;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	first = NewNode(0);
	first->next = first;
	last = first;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	int element;
	struct node *tmp;
	element = StrToInt(Edit1->Text);
	tmp = NewNode(element);
	tmp->next = first->next;
	first->next = tmp;
	if (tmp->next == first) last=tmp;
	printList();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int element;
	struct node *tmp;
	element = StrToInt(Edit1->Text);
	tmp = NewNode(element);
	tmp->next = last->next;
	last->next = tmp;
	last = tmp;
	printList();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int element;
	struct node *tmp;
	element = StrToInt(Edit2->Text);
	tmp = SearchNode(element);
	if(tmp) Memo1->Lines->Add(IntToStr(element)+" has been found!");
	else Memo1->Lines->Add(IntToStr(element)+" CANNOT be found!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int element, element_1;
	struct node *tmp, *new_tmp;
	element = StrToInt(Edit3->Text);
	element_1 = StrToInt(Edit4->Text);
	tmp = SearchNode(element);
	new_tmp = NewNode(element_1);
	if(tmp)
	{
		new_tmp = NewNode(element_1);
		new_tmp->next = tmp->next;
		tmp->next = new_tmp;
		printList();
	}else{
		Memo1->Lines->Add(IntToStr(element)+" CANNOT be found so not added!");
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int n, r, element, i;
	struct node *p, *tmp, *pointer;
	n = StrToInt(Edit5->Text);
	r = StrToInt(Edit6->Text);
	p = NewNode(0);
	pointer = p;
	for (i = 0; i < n; i++) {
		element = rand()%r;
		tmp = NewNode(element);
		pointer->next = tmp;
		pointer = tmp;
	}
	pointer->next = last->next;
	last->next = p->next;
	last = pointer;
	printList();
}
//---------------------------------------------------------------------------
struct node *SearchNodeBefore(int element)
{
	struct node *p;
	p = first;
	do{
		if(p->next->data==element) return p;
		p = p->next;
	}while(p!=first);
	return NULL;
}

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int element, element_1;
	struct node *tmp, *new_tmp;
	element = StrToInt(Edit3->Text);
	element_1 = StrToInt(Edit4->Text);
	tmp = SearchNodeBefore(element);
	new_tmp = NewNode(element_1);
	if(tmp)
	{
		new_tmp = NewNode(element_1);
		new_tmp->next = tmp->next;
		tmp->next = new_tmp;
		printList();
	}else{
		Memo1->Lines->Add(IntToStr(element)+" CANNOT be found so not added!");
	}
	

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button7Click(TObject *Sender)
{
	int element;
	struct node *tmp, *tmp_1;
	element = StrToInt(Edit2->Text);
	tmp = SearchNodeBefore(element);
	if(tmp)
	{
		tmp_1 = tmp->next;
		tmp->next = tmp_1->next;
		free(tmp_1);
		printList();
	}else{
		Memo1->Lines->Add(IntToStr(element)+" CANNOT be found so not deleted!");
    }


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	struct node *tmp;
	tmp = first->next;
	first->next = first;
	last = first;
	free(tmp);
	Form1->Memo1->Lines->Add("All have been deleted!");
	printList();
}
//---------------------------------------------------------------------------

