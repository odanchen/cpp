void read_arr(long long arr[], int &length) {
    cin >> length;
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
}

void sort_arr(long long arr[], int length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (arr[j] > arr[i]) swap(arr[i], arr[j]);
        }
    }
}

void add_element(int arr[], int &length, int &add_idx, int &add_num) {
    cin >> add_idx >> add_num;
    for (int i = length; i >= add_idx - 1; i--) {
        arr[i + 1] = arr[i];
    }
    arr[add_idx - 1] = add_num;
    length++;
}

void print_arr(int arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
}

void delete_element(int arr[], int &length, int &del_idx) {
    cin >> del_idx;
    for (int i = del_idx; i < length; i++) {
        arr[i - 1] = arr[i];
    }
    length--;
}

double average_num(int arr[] ,int length) {
    long long sum = 0;
    double counter = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
        counter += 1;
    }
    if (counter == 0) return 0;
    else return sum / counter;
}
