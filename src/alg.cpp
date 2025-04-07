// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++count;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      count++;
      left++;
      right--;
    }else if (sum < value) {
      left++;
    }else {
      right--;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    int first_pos = len;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] >= target) {
        first_pos = mid;
        right = mid - 1;
      }else {
        left = mid + 1;
      }
    }

    left = i + 1;
    right = len - 1;
    int last_pos = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] <= target) {
        last_pos = mid;
        left = mid + 1;
      }else {
        right = mid - 1;
      }
    }

    if (first_pos <= last_pos) {
      count += (last_pos - first_pos + 1);
    }
  }
  return count;
}
