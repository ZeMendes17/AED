A = load("data_solution1.txt");

n = A(:,1);
t = A(:,4);

plot(n,t)
grid on;

semilogy(n,t);
title("Solution 1")
xlabel("Nº de moves")
ylabel("Tempo (em segundos)")
grid;
figure
plot(n,log10(t))

t_log = log10(t); % serve para por o eixo dos yy sem x10

N = [n(20:end) 1+0*n(20:end)]; % é onde começa a estabilizar
Coefs = pinv(N)*t_log(20:end);

hold on
grid;
Ntotal = [n n*0+1];
plot(n,Ntotal*Coefs, 'k');
title("Solution 1")
xlabel("Nº de moves")
ylabel("Tempo em logaritmo de base 10 (em segundos)")

t800_log = [800 1] * Coefs; % obter o valor para 800
t800 = 10^t800_log / 3600 / 24 / 365 % valor em dias