sol1 = load("data_solution1.txt");
sol2 = load("data_solution2.txt");
sol3 = load("data_solution3.txt");
sol4 = load("data_solution4.txt");
sol5 = load("data_solution5.txt");

n_sol1 = sol1(:,1);
n_sol2 = sol2(:,1);
n_sol3 = sol3(:,1);
n_sol4 = sol4(:,1);
n_sol5 = sol5(:,1);

t_sol1 = sol1(:,4);
t_sol2 = sol2(:,4);
t_sol3 = sol3(:,4);
t_sol4 = sol4(:,4);
t_sol5 = sol5(:,4);

semilogy(n_sol1,t_sol1, 'b-')
hold on;
semilogy(n_sol2,t_sol2, 'r.')
semilogy(n_sol3,t_sol3, 'go-')
semilogy(n_sol4,t_sol4, 'k*-')
semilogy(n_sol5,t_sol5, 'm+-')
hold off;

legend("Solution 1", "Solution 2", "Solution 3", "Solution 4", "Solution 5");
title("Comparação entre todas as Soluções")
xlabel("Nº de moves")
ylabel("Tempo (em segundos)")
grid on

%% com o n moves e o effort

e_sol1 = sol1(:,3);
e_sol2 = sol2(:,3);
e_sol3 = sol3(:,3);
e_sol4 = sol4(:,3);
e_sol5 = sol5(:,3);

figure(2)
semilogy(n_sol1,e_sol1, 'b-')
hold on;
semilogy(n_sol2,e_sol2, 'r.')
semilogy(n_sol3,e_sol3, 'go-')
semilogy(n_sol4,e_sol4, 'k*-')
semilogy(n_sol5,e_sol5, 'm+-')
hold off;

legend("Solution 1", "Solution 2", "Solution 3", "Solution 4", "Solution 5");
title("Comparação entre todas as Soluções")
xlabel("Nº de moves")
ylabel("Effort de cada função")
grid on