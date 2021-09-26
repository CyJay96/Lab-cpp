#pragma once

template <class Type>
bool compare(Type a1, Type a2) {
	return a1 < a2;
}

bool compare(char* a1, char* a2) {
	return strcmp(a1, a2) <= 0;
}

template <class Type>
void mergeSort(Type* a, int left, int right) {
	if (left < right) {
		int split = (left + right) / 2;
		mergeSort(a, left, split);
		mergeSort(a, split + 1, right);

		int p_left = left;
		int p_right = split + 1;
		int k = 0;

		Type* res = new Type[right - left + 1];

		while (p_left <= split && p_right <= right) {
			if (compare(a[p_left], a[p_right])) {
				res[k++] = a[p_left++];
			}
			else {
				res[k++] = a[p_right++];
			}
		}
		while (p_left <= split) {
			res[k++] = a[p_left++];
		}
		while (p_right <= right) {
			res[k++] = a[p_right++];
		}
		for (k = 0; k < right - left + 1; k++) {
			a[left + k] = res[k];
		}
	}
}