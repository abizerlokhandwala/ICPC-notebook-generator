//Gaussian elimination
const double EPS = 1e-9;
vector<double> GaussianElimination(const vector<vector<double> >& A, const vector<double>& b) {
    int i, j, k, pivot, n = A.size();
    vector<vector<double> > B(n, vector<double>(n+1));
    vector<double> x(n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) B[i][j] = A[i][j];
        B[i][n] = b[i];
    }
    for(i = 0; i < n; i++) {
        for(pivot = j = i; j < n; ++j) if(fabs(B[j][i]) > fabs(B[pivot][i])) pivot = j;
        swap(B[i], B[pivot]);
        if(fabs(B[i][i]) < EPS) return vector<double>();
        for(j = n; j >= i; --j) B[i][j] /= B[i][i];
        for(j = 0; j < n; j++) if(i != j) for(k = i+1; k <= n; ++k) B[j][k] -= B[j][i] * B[i][k];
    }
    for(i = 0; i < n; i++) x[i] = B[i][n];
    return x;
}