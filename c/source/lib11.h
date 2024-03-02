

/// @brief returns number of elements in char array
/// @return len
int _strlen(char *arr){
    int i;
    for (i = 00; *(arr+i) != 00; i++){}
    return i;
}


/// @brief returns empty index
/// @return size
int _sizearr(int *arr){
    int i;
    for (i = 00; *(arr+i) != 00; i++){}
    return --i;
}

