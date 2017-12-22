// lower_bound(int *start, int *end, int x)

int* find_lower(int *start, int *end, int x){
    int* m = (end - start) / 2 + start;
    if(start == end)
        return start;
    if(*m < x)
        return find_lower(m+1, end, x);
    else
        return find_lower(start, m, x);
}

// upper_bound(int *start, int *end, int x)

int* find_upper(int *start, int *end, int x){
    if(start == end)
        return start;
    int *m = (end - start) / 2 + start;
    if(*m <= x)
        return find_upper(m+1, end, x);
    else
        return find_upper(start, m, x);
}
