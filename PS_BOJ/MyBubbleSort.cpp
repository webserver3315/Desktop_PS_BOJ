void bubblesort(int* arr, int length) {//�ҷ��Լ�
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

void bubblesort2(int* arr, int length) {//��Ȯ�� �����Լ�. i�� �پ��ٴ� ���� ����. �� �� ������ ���� ������ ���� ū ���Ұ� �ֿ������� ������.
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

void bubblesort3(int* arr, int length) {//�ҷ��Լ� ����_Fail
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

void bubblesort4(int* arr, int length) {//�ҷ��Լ� ������ ����_Success. �׷��� ������ �����������, 2�� �����Ⱥ��� �����ϹǷ� ��������.
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