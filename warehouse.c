#include "order.h"
#include "bench.h"
#include <stdio.h>

void addTo(int slot);
int compareSlots();
void emptySlot(int slot);

	int slot0count = 0;
	int slot1count = 0;
	int slot2count = 0;
	int slot3count = 0;
	int slot4count = 0;

int main(int argc, char **argv) {

	if (argc<2) {
		printf("Please invoke as %s <order_file>\n",argv[0]);
		return 1;
	}
	if (!openOrder(argv[1])) {
		return 1;
	}

	do {
		int pn=nextPartNumber();
		int bin=pn/10;

		/* ----------------------------------------------------------------------
		The following code does the job, but very inefficiently.
		Replace this code with your own code to handle the
		slots on the workbench more intelligently (and earn
		more profit.)
		-----------------------------------------------------------------------*/
		/*int bin0count = 0;
		int bin1count = 0;
		int bin2count = 0;
		int bin3count = 0;
		int bin4count = 0;
		int bin5count = 0;
		int bin6count = 0;
		int bin7count = 0;
		int bin8count = 0;
		int bin9count = 0;
		*/

		for(int i = 0; i<5; i= i+1){
			if(binInSlot(i) == bin){
				addTo(i);
				break;
			}
			if(i == 4 && binInSlot(i) != bin){
				int x = compareSlots();
				//printf("%d\n", x);
				//printf("%d\n", slot0count);
				//printf("%d\n", slot1count);
				//printf("%d\n", slot2count);
				//printf("%d\n", slot3count);
				//printf("%d\n", slot4count);
				fetchBin(bin,x);
				emptySlot(x);
				addTo(x);
			}
		}
		
		//if (binInSlot(0)!=bin) { fetchBin(bin,0); } // Always use slot 0

	} while(fetchNextPart());
	closeOrder();
	return 0;
}

void emptySlot(int slot){
	switch(slot) {
		case 0 :
			slot0count = 0;
			break;
		case 1 :
			slot1count = 0;
			break;
		case 2 :
			slot2count = 0;
			break;
		case 3 :
			slot3count = 0;
			break;
		case 4 :
			slot4count = 0;
			break;
	}
}

void addTo(int slot){
	switch(slot) {
		case 0 :
			slot0count = slot0count + 1;
			break;
		case 1 :
			slot1count = slot1count + 1;
			break;
		case 2 :
			slot2count = slot2count + 1;
			break;
		case 3 :
			slot3count = slot3count + 1;
			break;
		case 4 :
			slot4count = slot4count + 1;
			break;
	}
}

int compareSlots(){
	if(slot0count <= slot1count && slot0count <= slot2count && slot0count <= slot3count && slot0count <= slot4count){
		return 0;
	}
	if(slot1count <= slot0count && slot1count <= slot2count && slot1count <= slot3count && slot1count <= slot4count){
		return 1;
	}
	if(slot2count <= slot1count && slot2count <= slot0count && slot2count <= slot3count && slot2count <= slot4count){
		return 2;
	}
	if(slot3count <= slot1count && slot3count <= slot2count && slot3count <= slot0count && slot3count <= slot4count){
		return 3;
	}else{
		return 4;
	}
}


/*
void addTo(int bin){
	switch(bin) {
		case 0 :
			bin0count = bin0count + 1;
			break;
		case 1 :
			bin1count = bin1count + 1;
			break
		case 2 :
			bin2count = bin2count + 1;
			break;
		case 3 :
			bin3count = bin3count + 1;
			break;
		case 4 :
			bin4count = bin4count + 1;
			break;
		case 5 :
			bin5count = bin5count + 1;
			break;
		case 6 :
			bin6count = bin6count + 1;
			break
		case 7 :
			bin7count = bin7count + 1;
			break;
		case 8 :
			bin8count = bin8count + 1;
			break;
		case 9 :
			bin9count = bin9count + 1;
			break;
		case 10 :
			bin10count = bin10count + 1;
			break;
		case 11 :
			bin11count = bin11count + 1;
			break
		case 12 :
			bin12count = bin12count + 1;
			break;
		case 13 :
			bin13count = bin13count + 1;
			break;
		case 14 :
			bin14count = bin14count + 1;
			break;
		case 15 :
			bin15count = bin15count + 1;
			break;
		case 16 :
			bin16count = bin16count + 1;
			break
		case 17 :
			bin17count = bin17count + 1;
			break;
		case 18 :
			bin18count = bin18count + 1;
			break;
		case 19 :
			bin19count = bin19count + 1;
			break;
		case 20 :
			bin20count = bin20count + 1;
			break;
		case 21 :
			bin21count = bin21count + 1;
			break
		case 22 :
			bin22count = bin22count + 1;
			break;
		case 23 :
			bin23count = bin23count + 1;
			break;
		case 24 :
			bin24count = bin24count + 1;
			break;
		case 25 :
			bin25count = bin25count + 1;
			break;
		case 26 :
			bin26count = bin26count + 1;
			break
		case 27 :
			bin27count = bin27count + 1;
			break;
		case 28 :
			bin28count = bin28count + 1;
			break;
		case 29 :
			bin29count = bin29count + 1;
			break;
		case 30 :
			bin30count = bin30count + 1;
			break;
		case 31 :
			bin31count = bin31count + 1;
			break
		case 2 :
			bin2count = bin2count + 1;
			break;
		case 3 :
			bin3count = bin3count + 1;
			break;
		case 4 :
			bin4count = bin4count + 1;
			break;
		case 5 :
			bin5count = bin5count + 1;
			break;
		case 6 :
			bin6count = bin6count + 1;
			break
		case 7 :
			bin7count = bin7count + 1;
			break;
		case 8 :
			bin8count = bin8count + 1;
			break;
		case 9 :
			bin9count = bin9count + 1;
			break;
		case 0 :
			bin0count = bin0count + 1;
			break;
		case 1 :
			bin1count = bin1count + 1;
			break
		case 2 :
			bin2count = bin2count + 1;
			break;
		case 3 :
			bin3count = bin3count + 1;
			break;
		case 4 :
			bin4count = bin4count + 1;
			break;
		case 5 :
			bin5count = bin5count + 1;
			break;
		case 6 :
			bin6count = bin6count + 1;
			break
		case 7 :
			bin7count = bin7count + 1;
			break;
		case 8 :
			bin8count = bin8count + 1;
			break;
		case 9 :
			bin9count = bin9count + 1;
			break;
		case 0 :
			bin0count = bin0count + 1;
			break;
		case 1 :
			bin1count = bin1count + 1;
			break
		case 2 :
			bin2count = bin2count + 1;
			break;
		case 3 :
			bin3count = bin3count + 1;
			break;
		case 4 :
			bin4count = bin4count + 1;
			break;
		case 5 :
			bin5count = bin5count + 1;
			break;
		case 6 :
			bin6count = bin6count + 1;
			break
		case 7 :
			bin7count = bin7count + 1;
			break;
		case 8 :
			bin8count = bin8count + 1;
			break;
		case 9 :
			bin9count = bin9count + 1;
			break;
		default :
		 printf("Invalid grade\n" );
   }
}
*/




