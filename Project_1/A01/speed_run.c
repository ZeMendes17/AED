//
// AED, August 2022 (Tomás Oliveira e Silva)
//
// First practical assignement (speed run)
//
// Compile using either
//   cc -Wall -O2 -D_use_zlib_=0 solution_speed_run.c -lm
// or
//   cc -Wall -O2 -D_use_zlib_=1 solution_speed_run.c -lm -lz
//
// Place your student numbers and names here
//   N.Mec. XXXXXX  Name: XXXXXXX
//


//
// static configuration
//

#define _max_road_size_  800  // the maximum problem size
#define _min_road_speed_   2  // must not be smaller than 1, shouldnot be smaller than 2
#define _max_road_speed_   9  // must not be larger than 9 (only because of the PDF figure)


//
// include files --- as this is a small project, we include the PDF generation code directly from make_custom_pdf.c
//

#include <math.h>
#include <stdio.h>
#include "../P02/elapsed_time.h"
#include "make_custom_pdf.c"


//
// road stuff
//

static int max_road_speed[1 + _max_road_size_]; // positions 0.._max_road_size_

static void init_road_speeds(void)
{
  double speed;
  int i;

  for(i = 0;i <= _max_road_size_;i++)
  {
    speed = (double)_max_road_speed_ * (0.55 + 0.30 * sin(0.11 * (double)i) + 0.10 * sin(0.17 * (double)i + 1.0) + 0.15 * sin(0.19 * (double)i));
    max_road_speed[i] = (int)floor(0.5 + speed) + (int)((unsigned int)random() % 3u) - 1;
    if(max_road_speed[i] < _min_road_speed_)
      max_road_speed[i] = _min_road_speed_;
    if(max_road_speed[i] > _max_road_speed_)
      max_road_speed[i] = _max_road_speed_;
  }
}


//
// description of a solution
//

typedef struct
{
  int n_moves;                         // the number of moves (the number of positions is one more than the number of moves)
  int positions[1 + _max_road_size_];  // the positions (the first one must be zero)
  int move_speed[1 + _max_road_size_][2]; // to register the move number and speed in the position
}
solution_t;


//
// the (very inefficient) recursive solution given to the students
//

static solution_t solution_1,solution_1_best,solution_2,solution_2_best,solution_3,solution_3_best,solution_4,solution_4_best,solution_5,solution_5_best,solution_6,solution_6_best;
static double solution_1_elapsed_time, solution_2_elapsed_time,solution_3_elapsed_time,solution_4_elapsed_time,solution_5_elapsed_time,solution_6_elapsed_time; // time it took to solve the problem
static unsigned long solution_1_count, solution_2_count,solution_3_count,solution_4_count,solution_5_count,solution_6_count; // effort dispended solving the problem
static int sol_found;
static int best_moves_speed[_max_road_size_][2]; // apenas vai ser usado na solution_3


static void solution_1_recursion(int move_number,int position,int speed,int final_position)
{
  int i,new_speed;

  // record move
  solution_1_count++;
  solution_1.positions[move_number] = position;
  // is it a solution?
  if(position == final_position && speed == 1)
  {
    // is it a better solution?
    if(move_number < solution_1_best.n_moves)
    {
      solution_1_best = solution_1;
      solution_1_best.n_moves = move_number;
    }
    return;
  }
  // no, try all legal speeds
  for(new_speed = speed - 1;new_speed <= speed + 1;new_speed++)
    if(new_speed >= 1 && new_speed <= _max_road_speed_ && position + new_speed <= final_position)
    {
      for(i = 0;i <= new_speed && new_speed <= max_road_speed[position + i];i++)
        ;
      if(i > new_speed)
        solution_1_recursion(move_number + 1,position + new_speed,new_speed,final_position);
    }
}

static void solution_2_recursion(int move_number,int position,int speed,int final_position)
{
  int i,new_speed;

  // record move
  solution_2_count++;
  solution_2.positions[move_number] = position;
  // is it a solution?
  if(position == final_position && speed == 1)
  {
    // is it a better solution?
    if(move_number < solution_2_best.n_moves)
    {
      solution_2_best = solution_2;
      solution_2_best.n_moves = move_number;
    }
    return;
  }
  // no, try all legal speeds
  for(new_speed = speed + 1;new_speed >= speed - 1;new_speed--) // apenas é alterado a velocidade, para testar primeiro a mais rapida (nao altera nada na solução)
    if(new_speed >= 1 && new_speed <= _max_road_speed_ && position + new_speed <= final_position) // continua a fazer todas as possibilidades (é necessario cortar os ramos)
    {
      for(i = 0;i <= new_speed && new_speed <= max_road_speed[position + i];i++)
        ;
      if(i > new_speed)
        solution_2_recursion(move_number + 1,position + new_speed,new_speed,final_position);
    }
}

static void solution_3_recursion(int move_number,int position,int speed,int final_position)
{
  int i,new_speed;

  // record move
  solution_3_count++;
  solution_3.positions[move_number] = position;
  // is it a solution?
  if(position == final_position && speed == 1)
  {
    // is it a better solution?
    if(move_number < solution_3_best.n_moves)
    {
      solution_3_best = solution_3;
      solution_3_best.n_moves = move_number;
    }
    return;
  }

  if(best_moves_speed[position][0] >= move_number && best_moves_speed[position][1] <= speed){
    return;
  }
  else{
    best_moves_speed[position][0] = move_number;
    best_moves_speed[position][1] = speed;
  }
  // no, try all legal speeds
  for(new_speed = speed + 1;new_speed >= speed - 1;new_speed--) // apenas é alterado a velocidade, para testar primeiro a mais rapida (nao altera nada na solução)
    if(new_speed >= 1 && new_speed <= _max_road_speed_ && position + new_speed <= final_position) // continua a fazer todas as possibilidades (é necessario cortar os ramos)
    {
      for(i = 0;i <= new_speed && new_speed <= max_road_speed[position + i];i++)
        ;
      if(i > new_speed)
        solution_3_recursion(move_number + 1,position + new_speed,new_speed,final_position);
    }
}

// solution 3 --> fazer com array em que as speeds sao preenchidas com 0 e os moves com maxroadsize e fazer as comparações com esse
// assim em principio nao da erro

static void solution_4_recursion(int move_number,int position,int speed,int final_position)
{
  int i,k,new_speed,count_speed;

  for(k = position; k > position-speed; k--)
  {
    solution_4.move_speed[k][0] = move_number;
    solution_4.move_speed[k][1] = speed;
  }

  // record move
  solution_4_count++;
  solution_4.positions[move_number] = position;
  // is it a solution?
  if(position == final_position && speed == 1)
  {
    // is it a better solution?
    if(move_number < solution_4_best.n_moves)
    {
      solution_4_best = solution_4;
      solution_4_best.n_moves = move_number;
    }
    sol_found = 1;
    return;
  }
  
  if(sol_found == 1){
        if(solution_4_best.move_speed[position + 1][0] <= move_number + 1 || solution_4_best.move_speed[position + 1][1] >= new_speed) // fazer testes para verificar se os novos valores sao meljore
          return;
      }
  
  // no, try all legal speeds
  for(new_speed = speed + 1;new_speed >= speed - 1;new_speed--) // apenas é alterado a velocidade, para testar primeiro a mais rapida (nao altera nada na solução)
    if(new_speed >= 1 && new_speed <= _max_road_speed_ && position + new_speed <= final_position) // continua a fazer todas as possibilidades (é necessario cortar os ramos)
    {
    //   count_speed = (new_speed * (new_speed + 1) / 2);
    //  // count_speed vai ser o valor da nova velocidade mais as velocidades menores
    
    //   if(count_speed + position > final_position)
    //   {
    //     return;
    //   }

      for(i = 0;i <= new_speed && new_speed <= max_road_speed[position + i];i++)
        ;
      if(i > new_speed)
        solution_4_recursion(move_number + 1,position + new_speed,new_speed,final_position);
    }
}

static void solution_5_recursion(int move_number,int position,int speed,int final_position)
{


  int i,k,new_speed;

  for(k = position; k > position-speed; k--)
  {
    solution_5.move_speed[k][0] = move_number;
    solution_5.move_speed[k][1] = speed;
  }

  // record move
  solution_5_count++;
  solution_5.positions[move_number] = position;

  // is it a solution?
  if(position == final_position && speed == 1)
  {
    // is it a better solution?
    if(move_number < solution_5_best.n_moves)
    {
      solution_5_best = solution_5;
      solution_5_best.n_moves = move_number;
    }
    sol_found = 1;
    return;
  }

  // no, try all legal speeds
  for(new_speed = speed + 1;new_speed >= speed - 1;new_speed--)
  {
    // travar ex 5+4+3+2+1 + position > final_position ---> chama a recursao se a dif menor 3 -> return else recursao
    // count_speed = (new_speed * (new_speed - 1) / 2);
     // count_speed vai ser o valor da nova velocidade mais as velocidades menores
    
    //  if(count_speed + position > final_position)
    //  {
    //    return;
    //  }

    if(new_speed >= 1 && new_speed <= _max_road_speed_ && position + new_speed <= final_position)
    {
      for(i = 0;i <= new_speed && new_speed <= max_road_speed[position + i];i++)
        ;
      if(i > new_speed){
        solution_5_recursion(move_number + 1,position + new_speed,new_speed,final_position);
        if(sol_found == 1){
          if(solution_5_best.move_speed[position + 1][0] <= move_number + 1 || solution_5_best.move_speed[position + 1][1] >= new_speed) // fazer testes para verificar se os novos valores sao meljore
                                                                                                                                       // se forem menor ou iguais a solução encontarda em primeiro lugar vai ser melhor 
            return;
          else
          {
            solution_5_recursion(move_number + 1,position + new_speed,new_speed,final_position);
          }
        }
        // a recursoa vai acabar aqui, logo para nao ter mais iteraçoes testar aqui se a velocidade e o numero de movimentos é valido
      }
    }
  }
}

static void solution_6_while(int final_position) // ja esta?
{
  int move_number, position, speed, new_speed, i,minus_flag, same_flag, plus_flag, val_temporario; // o count vai servir para por as velocidades no array em baixo
  move_number = 0; position = 0; speed = 0; minus_flag = 0; same_flag = 0; plus_flag = 0;
  int speeds_position[800]; // guarda a velocidade das posições em que esteve
  
  while(!(position == final_position && speed == 1)) // quando a solução é encontrada
  {
    solution_6_count++;
  
    if(minus_flag == 1) // diminui a velocidade
    {
      minus_flag = 0;
      new_speed = speed - 1;
    }
    else if(same_flag == 1) // mantem a velocidade
    {
      same_flag = 0;
      new_speed = speed;
    }
    else{ // a melhor opção esta no else pois caso nenhuma flag esteja ativa vem para aqui na mesma
          // aumenta a velocidade
      plus_flag = 0;
      new_speed = speed + 1;
    }

    if(new_speed >= 1 && new_speed <= _max_road_speed_ && position + new_speed <= final_position)
    {
      
      for(i = 0;i <= new_speed && new_speed <= max_road_speed[position + i];i++) // vai verificar se é possivel esta new_speed
      ;
      if(i > new_speed){
        speeds_position[move_number] = speed; // define a velocidade naquela posição
        solution_6.positions[move_number] = position;
        move_number += 1;
        position += new_speed;
        speed = new_speed;
        minus_flag = 0; same_flag = 0; plus_flag = 0; // resetar as flags
        // printf("% d %d", position,speed);
        continue; // depois de dar update aos valores, faz uma nova iteração no while
      }
      else{
        if(minus_flag == 1){
          minus_flag = 0;
          // altera a posição
          position -= speeds_position[move_number];
          speeds_position[move_number] = 0;
          move_number--; // volta atras
          val_temporario = speeds_position[move_number] - speeds_position[move_number - 1]; // da nos o valor da speed anterior
          // solution_6.positions[move_number] = 0;
          // speed = speeds_position[count] - 1;
          if(val_temporario == 1){
            plus_flag = 0;
            same_flag = 1;
            continue;
          }
          else if(val_temporario == 0){
            same_flag = 0;
            minus_flag = 1;
            continue;
          }
          else{
            // tambem tem de ir atras
            while(val_temporario == -1){
              position -= speeds_position[move_number];
              solution_6.positions[move_number] = 0;
              speeds_position[move_number] = 0;
              move_number--; // volta atras
              val_temporario = speeds_position[move_number] - speeds_position[move_number - 1]; // da nos o valor da speed anterior
              // speed = speeds_position[count] - 1;
            }
            if(val_temporario == 1){
              plus_flag = 0;
              same_flag = 1;
              continue;
            }
            else if(val_temporario == 0){
              same_flag = 0;
              minus_flag = 1;
              continue;
            }
          }
        }
        else if(same_flag == 1){
          same_flag = 0;
          minus_flag = 1;
          continue;
        }
        else{
          plus_flag = 0;
          same_flag = 1;
          continue;
        }
      }
    }
    else{
      if(minus_flag == 1){
        minus_flag = 0;
        // altera a posição
        position -= speeds_position[move_number];
        speeds_position[move_number] = 0;
        move_number--; // volta atras
        val_temporario = speeds_position[move_number] - speeds_position[move_number - 1]; // da nos o valor da speed anterior

        while(val_temporario == -1){
          position -= speeds_position[move_number];
          solution_6.positions[move_number] = 0;
          speeds_position[move_number] = 0;
          move_number--; // volta atras
          val_temporario = speeds_position[move_number] - speeds_position[move_number - 1]; // da nos o valor da speed anterior
          // speed = speeds_position[count] - 1;
        }

        if(val_temporario == 1){
          plus_flag = 0;
          same_flag = 1;
          continue;
        }
        else if(val_temporario == 0){
          same_flag = 0;
          minus_flag = 1;
          continue;
        }
      }
      else if(same_flag == 1){
        same_flag = 0;
        minus_flag = 1;
        continue;
      }
      else{
        plus_flag = 0;
        same_flag = 1;
        continue;
      }
    }
  }
}


static void solve_1(int final_position)
{
  if(final_position < 1 || final_position > _max_road_size_)
  {
    fprintf(stderr,"solve_1: bad final_position\n");
    exit(1);
  }
  solution_1_elapsed_time = cpu_time();
  solution_1_count = 0ul;
  solution_1_best.n_moves = final_position + 100;
  solution_1_recursion(0,0,0,final_position);
  solution_1_elapsed_time = cpu_time() - solution_1_elapsed_time;
}

static void solve_2(int final_position)
{
  if(final_position < 1 || final_position > _max_road_size_)
  {
    fprintf(stderr,"solve_2: bad final_position\n");
    exit(1);
  }
  solution_2_elapsed_time = cpu_time();
  solution_2_count = 0ul;
  solution_2_best.n_moves = final_position + 100;
  solution_2_recursion(0,0,0,final_position);
  solution_2_elapsed_time = cpu_time() - solution_2_elapsed_time;
}

static void solve_3(int final_position)
{
  int i;
  if(final_position < 1 || final_position > _max_road_size_)
  {
    fprintf(stderr,"solve_3: bad final_position\n");
    exit(1);
  }
  for(i = 0; i < _max_road_size_; i++)
  {
    best_moves_speed[i][0] = 0; // speed
    best_moves_speed[i][1] = _max_road_size_; // moves
  }
  solution_3_elapsed_time = cpu_time();
  solution_3_count = 0ul;
  solution_3_best.n_moves = final_position + 100;
  solution_3_recursion(0,0,0,final_position);
  solution_3_elapsed_time = cpu_time() - solution_3_elapsed_time;
}

static void solve_4(int final_position)
{
  if(final_position < 1 || final_position > _max_road_size_)
  {
    fprintf(stderr,"solve_4: bad final_position\n");
    exit(1);
  }
  solution_4_elapsed_time = cpu_time();
  solution_4_count = 0ul;
  solution_4_best.n_moves = final_position + 100;
  sol_found = 0;
  solution_4_recursion(0,0,0,final_position);
  solution_4_elapsed_time = cpu_time() - solution_4_elapsed_time;
}

static void solve_5(int final_position)
{
  if(final_position < 1 || final_position > _max_road_size_)
  {
    fprintf(stderr,"solve_5: bad final_position\n");
    exit(1);
  }
  solution_5_elapsed_time = cpu_time();
  solution_5_count = 0ul;
  solution_5_best.n_moves = final_position + 100;
  sol_found = 0;
  solution_5_recursion(0,0,0,final_position);
  // for(int l = 0; l <  _max_road_size_ + 1; l++)
  //   printf("%d-%d ", solution_5.move_speed[l][0], solution_5.move_speed[l][1]); // movimentos-speed
  
  solution_5_elapsed_time = cpu_time() - solution_5_elapsed_time;
}

static void solve_6(int final_position)
{
  // ok basicamente vai ser uma solução em que tenta ir o mais rapido possivel num loop while (unica opcao em que nao é usado a recursão)
  solution_6_elapsed_time = cpu_time();
  solution_6_count = 0ul;
  solution_6_best.n_moves = final_position + 100;
  solution_6_while(final_position);
  // o que fazer: começa com vel 0 e vai sempre tentar aumentar 1, depois 0 e -1 caso nao consiga, vai verificar as velocidades maximas com o for do stor
  // e caso nao consiga nenhum dos dois vai voltar á posição anterior e tentar uma menor. Vai dar store as posições, speeds em cada quadrado e mais se for
  // preciso (tentar dont know)
  solution_6_elapsed_time = cpu_time() - solution_6_elapsed_time;
}

//
// example of the slides
//

static void example(void)
{
  int i,final_position;

  srandom(0xAED2022);
  init_road_speeds();
  final_position = 30;
  solve_1(final_position);
  make_custom_pdf_file("example.pdf",final_position,&max_road_speed[0],solution_1_best.n_moves,&solution_1_best.positions[0],solution_1_elapsed_time,solution_1_count,"Plain recursion");
  printf("mad road speeds:");
  for(i = 0;i <= final_position;i++)
    printf(" %d",max_road_speed[i]);
  printf("\n");
  printf("positions:");
  for(i = 0;i <= solution_1_best.n_moves;i++)
    printf(" %d",solution_1_best.positions[i]);
  printf("\n");
}


//
// main program
//

int main(int argc,char *argv[argc + 1])
{
# define _time_limit_  3600.0
  int n_mec,final_position,print_this_one;
  char file_name[64];

  // generate the example data
  if(argc == 2 && argv[1][0] == '-' && argv[1][1] == 'e' && argv[1][2] == 'x')
  {
    example();
    return 0;
  }
  // initialization
  n_mec = (argc < 2) ? 0xAED2022 : atoi(argv[1]);
  srandom((unsigned int)n_mec);
  init_road_speeds();
  // run all solution methods for all interesting sizes of the problem
  final_position = 1;
  solution_4_elapsed_time = 0.0;
  // printf("    + --- ---------------- --------- +\n");
  // printf("    |                greedy recursion |\n");
  // printf("--- + --- ---------------- --------- +\n");
  // printf("  n | sol            count  cpu time |\n");
  // printf("--- + --- ---------------- --------- +\n");
  while(final_position <= _max_road_size_/* && final_position <= 20*/)
  {
    print_this_one = (final_position == 10 || final_position == 20 || final_position == 50 || final_position == 100 || final_position == 200 || final_position == 400 || final_position == 800) ? 1 : 0;
    printf("%3d ",final_position);
    // first solution method (very bad)
    if(solution_4_elapsed_time < _time_limit_)
    {
      solve_4(final_position);
      if(print_this_one != 0)
      {
        sprintf(file_name,"%03d_4_107188.pdf",final_position);
        make_custom_pdf_file(file_name,final_position,&max_road_speed[0],solution_4_best.n_moves,&solution_4_best.positions[0],solution_4_elapsed_time,solution_4_count,"Recursion with storage 2 107188");
      }
      printf(" %3d %16lu %9.3e ",solution_4_best.n_moves,solution_4_count,solution_4_elapsed_time);
    }
    else
    {
      solution_4_best.n_moves = -1;
      // printf("                                |");
    }
    // second solution method (less bad)
    // ...

    // done
    printf("\n");
    fflush(stdout);
    // new final_position
    if(final_position < 50)
      final_position += 1;
    else if(final_position < 100)
      final_position += 5;
    else if(final_position < 200)
      final_position += 10;
    else
      final_position += 20;
  }
  // printf("--- + --- ---------------- --------- +\n");
  return 0;
# undef _time_limit_
}
