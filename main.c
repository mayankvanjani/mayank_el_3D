#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "parser.h"

int main( int argc, char** argv ) {

  screen s;
  struct matrix *edges;
  struct matrix *transform;
  color c;
  c.red = 0;
  c.green = 255;
  c.blue = 255;

  edges = new_matrix(4, 4);
  transform = new_matrix(4, 4);

  if ( argc == 2 )
    parse_file( argv[1], transform, edges, s );
  else
    parse_file( "stdin", transform, edges, s );

  add_edge( edges, 250,0,0, 250,25,0 );//M                       
  add_edge( edges, 250,25,0, 263,0,0 );
  add_edge( edges, 263,0,0, 275,25,0 );
  add_edge( edges, 275,25,0, 275,0,0 );
  add_edge( edges, 280,0,0, 293,25,0 );//A                      
  add_edge( edges, 293,25,0, 305,0,0 );
  add_edge( edges, 287,13,0, 299,13,0 );
  add_edge( edges, 310,0,0, 325,25,0 );//Y                               
  add_edge( edges, 318,13,0, 305,25,0 );
  add_edge( edges, 330,0,0, 343,25,0 );//A                              
  add_edge( edges, 343,25,0, 355,0,0 );
  add_edge( edges, 337,13,0, 349,13,0 );
  add_edge( edges, 360,0,0, 360,25,0 );//N                         
  add_edge( edges, 360,25,0, 385,0,0 );
  add_edge( edges, 385,0,0, 385,25,0 );
  add_edge( edges, 390,0,0, 390,25,0 );//K                           
  add_edge( edges, 390,13,0, 408,25,0 );
  add_edge( edges, 395,14,0, 408,0,0 );
  draw_lines(edges, s, c);

  save_extension(s, "dimensional.png");
  display(s);

  free_matrix( transform );
  free_matrix( edges );
}  
