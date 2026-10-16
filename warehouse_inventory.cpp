//Aplikasi Inventaris Gudang Toko

//Group 4

//Anggota:
//- Carmenita Angelica - [ID removed]
//- Ivana Joyceline - [ID removed]
//- Nadya Angelie Lislie - [ID removed]
//- Ryu Orlando Tamin - [ID removed]


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	char nama[256], kategori[256];
	int jumlah;
	struct Node *next, *prev;
}*head=NULL, *tail=NULL;

struct Node *newNode(char nama[], char kategori[], int jumlah){
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	strcpy(node->nama, nama);
	strcpy(node->kategori, kategori);
	node->jumlah = jumlah;
	node->next = node->prev = NULL;
}

void pushHead(char nama[], char kategori[], int jumlah){
	struct Node *node = newNode(nama, kategori, jumlah);
	node->next = head;
	head->prev = node;
	head = node;
}

void pushTail(char nama[], char kategori[], int jumlah){
	struct Node *node = newNode(nama, kategori, jumlah);
	tail->next = node;
	node->prev = tail;
	tail = node;
}

void popHead(int jumlah){
	if(head->jumlah - jumlah <= 0){
		printf("Berhasil mengambil %s. Sisa stok: 0.\n", head->nama);
		if(head == tail){
			free(head);
			head = tail = NULL;
		}else{
			struct Node *temp = head;
			head->next->prev = NULL;
			head = head->next;
			free(temp);
		}
	}else{
		printf("Berhasil mengambil %s. Sisa stok: %d.\n", head->nama, head->jumlah - jumlah);
		head->jumlah = head->jumlah - jumlah;
	}
}

void popTail(int jumlah){
	if(tail->jumlah - jumlah <= 0){
		printf("Berhasil mengambil %s. Sisa stok: 0.\n", tail->nama);
		if(head == tail){
			free(head);
			head = tail = NULL;
		}else{
			struct Node *temp = tail;
			tail->prev->next = NULL;
			tail = tail->prev;
			free(temp);
		}
	}else{
		printf("Berhasil mengambil %s. Sisa stok: %d.\n", tail->nama, tail->jumlah - jumlah);
		tail->jumlah = tail->jumlah - jumlah;
	}
}

void view(){
	if(head==NULL){
		printf("Tidak ada barang.\n");
	}else{
		struct Node *curr = head;
		printf("____________________________________________________\n");
		printf("| Nama           | Kategori       | Jumlah         |\n");
		printf("|________________|________________|________________|\n");
		while(curr != NULL){
			printf("| %-15s| %-15s| %-15d|\n", curr->nama, curr->kategori, curr->jumlah);
			printf("|________________|________________|________________|\n");
			curr = curr->next;
		}
	}
	printf("\nEnter to continue");
	getchar();
	system("cls");
}

void filter(){
	if(head==NULL){
		printf("Tidak ada barang.\n");
	}else{
		char kategori[256];
		printf("Input kategori\n");
		printf(">> ");
		scanf("%[^\n]", kategori);getchar();
		struct Node *curr = head;
		int ada = 0;
		while(curr != NULL){
			if(strcmp(curr->kategori, kategori) == 0 && ada == 0){
				printf("____________________________________________________\n");
				printf("| Nama           | Kategori       | Jumlah         |\n");
				printf("|________________|________________|________________|\n");
				printf("| %-15s| %-15s| %-15d|\n", curr->nama, curr->kategori, curr->jumlah);
				printf("|________________|________________|________________|\n");
				ada = 1;
			}else if(strcmp(curr->kategori, kategori) == 0 && ada == 1){
				printf("| %-15s| %-15s| %-15d|\n", curr->nama, curr->kategori, curr->jumlah);
				printf("|________________|________________|________________|\n");
			}
			curr = curr->next;
		}
		if(ada == 0){
			printf("Barang tidak ditemukan.\n");
		}
	}
	printf("\nEnter to continue");
	getchar();
	system("cls");
}

void insert(){
	char nama[256], kategori[256];
	int jumlah;
	printf("Input nama barang\n");
	printf(">> ");
	scanf("%s", nama);getchar();
	printf("Input kategori barang\n");
	printf(">> ");
	scanf("%s", kategori);getchar();
	printf("Input jumlah barang\n");
	printf(">> ");
	scanf("%d", &jumlah);getchar();
	while(jumlah <= 0){
		printf("Jumlah barang tidak bisa lebih kecil atau sama dengan 0.\n");
		printf(">> ");
		scanf("%d", &jumlah);getchar();
	}
	struct Node *node = newNode(nama, kategori, jumlah);
	if(head == NULL){
		head = tail = node;
		printf("Berhasil menambahkan barang pertamamu.\n");
	}else if(strcmp(nama, head->nama) < 0){
		pushHead(nama, kategori, jumlah);
		printf("Berhasil menambahkan barang baru.\n");
	}else if(strcmp(nama, head->nama) == 0){
		printf("Berhasil menambahkan jumlah %s dari %d menjadi %d.\n", nama, head->jumlah, head->jumlah + jumlah);
		head->jumlah = head->jumlah + jumlah;
	}else if(strcmp(nama, tail->nama) > 0){
		pushTail(nama, kategori, jumlah);
		printf("Berhasil menambahkan barang baru.\n");
	}else if(strcmp(nama, tail->nama) == 0){
		printf("Berhasil menambahkan jumlah %s dari %d menjadi %d.\n", nama, tail->jumlah, tail->jumlah + jumlah);
		tail->jumlah = tail->jumlah + jumlah;
	}else{
		struct Node *curr = head;
		while(curr->next != NULL){
			if(strcmp(nama, curr->next->nama) < 0){
				curr->next->prev = node;
				node->next = curr->next;
				curr->next = node;
				node->prev = curr;
				printf("Berhasil menambahkan barang baru.\n");
				break;
			}else if(strcmp(nama, curr->next->nama) == 0){
				printf("Berhasil menambahkan jumlah %s dari %d menjadi %d.\n", nama, curr->next->jumlah, curr->next->jumlah + jumlah);
				curr->next->jumlah = curr->next->jumlah + jumlah;
				break;
			}
			curr = curr->next;
		}	
	}
	printf("\nEnter to continue");
	getchar();
	system("cls");
}


void pop(){
	char nama[256];
	int jumlah;
	if(head == NULL){
		printf("Tidak ada barang untuk dihapus\n\n");
		printf("Enter to continue");
		getchar();
		system("cls");
		return;
	}
	printf("Input nama barang yang ingin diambil\n");
	printf(">> ");
	scanf("%[^\n]", nama);getchar();
	int ada = 0;
	
	while(ada == 0){
		struct Node *curr = head;
		while(curr!=NULL){
			if(strcmp(curr->nama, nama) == 0){
				ada = 1;
				break;
			}
			curr = curr->next;
		}
		if(ada == 0){
			printf("Barang tidak ada, mohon input nama barang yang ada\n");
			printf(">> ");
			scanf("%[^\n]", nama);getchar();
		}else{
			break;
		}
	}
	
	printf("Input jumlahnya\n");
	printf(">> ");
	scanf("%d", &jumlah);getchar();
	while(jumlah <= 0){
		printf("Jumlah barang yang akan diambil tidak bisa lebih kecil atau sama dengan 0.\n");
		printf(">> ");
		scanf("%d", &jumlah);getchar();
	}
	if(strcmp(nama, head->nama) == 0){
		popHead(jumlah);
	}else if(strcmp(nama, tail->nama) == 0){
		popTail(jumlah);
	}else{
		struct Node *curr = head;
		while(curr->next != NULL){
			if(strcmp(nama, curr->next->nama) == 0){
				if(curr->next->jumlah - jumlah <= 0){
					struct Node *temp = curr->next;
					temp->next->prev = curr;
					curr->next = temp->next;
					free(temp);
					printf("Berhasil mengambil %s. Sisa stok: 0.\n", nama);
				}else{
					curr->next->jumlah = curr->next->jumlah - jumlah;
					printf("Berhasil mengambil %s. Sisa stok: %d\n", nama, curr->next->jumlah);
				}
				break;
			}
			curr = curr->next;
		}
	}
	printf("\nEnter to continue");
	getchar();
	system("cls");
	return;

}




int menu(){
	int option;
	printf("Aplikasi Inventaris Gudang Toko\n");
	printf("================================\n");
	printf("1. View\n");
	printf("2. Filter\n");
	printf("3. Insert\n");
	printf("4. Delete\n");
	printf("5. Exit\n");
	printf("================================\n");
	printf(">> ");
	scanf("%d", &option);getchar();
	//Validasi opsi menu
	while(option < 1 || option > 5){
		printf("Mohon pilih opsi menu yang tertera.\n");
		printf(">> ");
		scanf("%d", &option);getchar();
	}
	return option;
}

int main(){
	int indikator = 1;
	while(indikator){
		int option = menu();
		switch(option){
			case 1:{ //View
				view();
				break;
			}
			case 2:{ //Filter
				filter();
				break;
			}
			case 3:{ //Insert
				insert();
				break;
			}
			case 4:{ //Delete
				pop();
				break;
			}
			case 5:{ //Exit
				indikator = 0;
				break;
			}
		}
	}
	system("cls");
	printf("Program berakhir.\n");
	
	
	
	
	return 0;
}




