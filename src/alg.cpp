// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  int l_index = 0;
  int r_index = len - 1;
  while (arr[r_index] > value && r_index != l_index) {
    r_index--;
  }

  while (arr[l_index] + arr[r_index] < value && l_index != r_index) {
    l_index++;
  }

  for (int i = l_index; i < r_index; ++i) {
    for (int j = i + 1; j <= r_index; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int findParis(int* arr, int value, int n, int l, int r) {
  int count = 0;
  int middle = (l + r) / 2;

  int l_indx = -1;
  int r_indx = -1;

  if (r < l) {
    return 0;
  } else if (n + arr[middle] == value) {
    count++;

    if (middle - 1 >= l) {
      l_indx = middle - 1;
    }

    if (middle + 1 <= r) {
      r_indx = middle + 1;
    }

    while (l_indx >= l && n + arr[l_indx] == value) {
      count++;
      l_indx--;
    }

    while (r_indx <= r && r_indx != -1 && n + arr[r_indx] == value) {
      count++;
      r_indx++;
    }

    return count;
  } else {
    if (n + arr[middle] < value) {
      return findParis(arr, value, n, middle + 1, r);
    }

    return findParis(arr, value, n, l, middle - 1);
  }
}
int countPairs3(int* arr, int len, int value) {
  int count = 0;

  for (int i = 0; i < len - 1; ++i) {
    count += findParis(arr, value, arr[i], i + 1, len - 1);
  }

  return count;
}
