void bubblesort(int* arr, int length) {//불량함수
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return;
}

void bubblesort2(int* arr, int length) {//정확한 버블함수. i가 줄어든다는 점에 유의. 한 번 정렬이 끝날 때마다 가장 큰 원소가 최우측으로 몰린다.
	for (int i = length - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return;
}

void bubblesort3(int* arr, int length) {//불량함수 개량_Fail
	for (int i = 1; i < length - 1; i++) {
		for (int j = 0; j < length - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return;
}

void bubblesort4(int* arr, int length) {//불량함수 개량을 개량_Success. 그런데 억지로 끼워맞춘거지, 2번 모범답안보다 난해하므로 지양하자.
	for (int i = 1; i <= length - 1; i++) {
		for (int j = 0; j < length - i; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return;
}