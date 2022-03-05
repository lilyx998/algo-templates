public int findNeedleInHay(String hay, String needle) {
    if(needle.length() == 0)
        return 0; 
    int[] failure = buildFailure(needle); 
    for(int i = 0, j = 0; i<hay.length(); i++){
        while(j != 0 && hay.charAt(i) != needle.charAt(j))
            j = failure[j-1]; 
        if(hay.charAt(i) == needle.charAt(j)){
            j++; 
            if(j == needle.length())
                return i-j+1;
        }
    }
    return -1; 
}

private int[] buildFailure(String str){
    int[] res = new int[str.length()]; 
    for(int i = 1, j = 0; i<str.length(); i++){
        while(j!=0 && str.charAt(i) != str.charAt(j))
            j = res[j-1]; 
        if(str.charAt(i) == str.charAt(j))
            j++; 
        res[i] = j; 
    }
    return res; 
}