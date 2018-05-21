    int N,Q;   
    int k, data;
    cin>>N>>Q;
    int **n = new int*[N];
    for(int i=0;i<N;i++)
    {
        cin>>k;
        n[i]= new int[k];
        for(int j=0;j<k;j++)
        {
            cin>>n[i][j];
        }
    }
    
    int a,b;
    for(int i=0;i<Q;i++)
    {
        
        cin>>a>>b;
        cout<<n[a][b]<<endl;
    }
	return 0;
}

