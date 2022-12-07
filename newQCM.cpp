#include <iostream>
#include <fstream>

using namespace std;

struct queue{
	char Q[100];
	char A[30], B[30], C[30], D[30];
	int n = 15;
};

//unsigned int n;

struct queue q[15], tmp;
//int a = 15;
int front = -1, rear = -1;

void enqueue(int n)
{
	rear = n;
	if(rear == 15){
		cout << "Queue overflowed!" << endl;
	}else{
		if(front == -1){
			front = 0;
		}
		cout << "<--Input the question and answer to the file-->" << endl;
		cout << "Question: " << n+1 << ". "; cin.getline(q[rear].Q, 100);
		cout << "Answer A: "; cin.getline(q[rear].A, 30);
		cout << "Answer B: "; cin.getline(q[rear].B, 30);
		cout << "Answer C: "; cin.getline(q[rear].C, 30);
		cout << "Answer D: "; cin.getline(q[rear].D, 30);
		rear++;
	}	
}

//void dequeue(queue q){ // remove from begin
//	element  *tmp;
//	tmp = q->front;
//	
////	delete tmp;
//	if(q->n == 1){
//		q->rear = NULL;
//	}
//	else if(q->n == 0) 
//	{
//		cout << "Data underflow"<< endl;
//	}
//	else if(q->n>1)
//	{
//		q->front = q->front->next;
//		delete tmp;
//	}
//	q->n--;
//}
//
void display(int i)
{
	cout << i+1 << ". " << q[i].Q << endl;
	cout << "\tA. " << q[i].A << endl;
	cout << "\tB. " << q[i].B << endl;
	cout << "\tC. " << q[i].C << endl;
	cout << "\tD. " << q[i].D << endl;
}

main()
{
	int number, opt;
	
	fstream file;
//	
//	queue *q;
//	q = emptyQueue();
	
	do{
		cout << "1. Input" << endl;
		cout << "2. Output" << endl;
		cout << "Choose option: "; cin >> opt;
		switch(opt){
			
			// Insertion 
			case 1:{
				cout << "Input number of Question: "; cin >> number;
	
				file.open("quize.txt",ios::app|ios::binary);cin.ignore();
				for(int i=0; i<number; i++)
				{
					enqueue(i);
					file.write((char*)&q[i], sizeof(queue));
				}
				file.close();
				
				break;
			}
			
			// 2. Display 
			case 2:{
				file.open("quize.txt", ios::in|ios::binary);
				int i=0;
				while(file.read((char*)&q[i] , sizeof(q[i]))){
					display(i);
					i++;
				}
				file.close();
				break;
			}
			case 3:{
				
				break;
			}
		}
	}while(opt!=7);
}