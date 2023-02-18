int const mu_N = 1e7 + 10;
bool isprime[mu_N] = {1, 1};  // �ж�i�Ƿ�Ϊ����,i=0,i=1��ʱ�򶼲������� ������ֱ�ӱ��
int prime[mu_N];              //������
int mu[mu_N];
int mu_f[mu_N];

void get_mu(long long n) {
    mu[1] = 1;  // ��� Ī����˹������
    // isprime[] ��� �Ƿ�������
    // prime[]  ���  ����
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (!isprime[i]) {
            prime[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            isprime[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0;
                break;
            }  //Ҳ����ֱ��break ��Ϊ���汾����ľ���0
            else
                mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1; i < n; i++) {
        mu_f[i] = mu_f[i - 1] + mu[i];
    }
}
