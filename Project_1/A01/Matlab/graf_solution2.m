A = load("data_solution2.txt");

n = A(:,1);
t = A(:,4);

plot(n,t)
grid on;

semilogy(n,t, 'r-');
title("Solution 2")
xlabel("Nº de moves")
ylabel("Tempo (em segundos)")
grid on;

%% comparação entre a solution 1 e a 2

B = load("data_solution1.txt");
n1 = B(:,1);
t1 = B(:,4);

figure(2)
semilogy(n1,t1, 'b-');
hold on;
semilogy(n,t,'r-')
legend('Solução 1', 'Solução 2')
title("Comparação entre Solution 1 e Solution 2")
xlabel("Nº de moves")
ylabel("Tempo (em segundos)")
grid on;