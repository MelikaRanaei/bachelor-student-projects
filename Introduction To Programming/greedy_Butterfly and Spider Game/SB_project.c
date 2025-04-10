
//  Created by Melika on 1/20/20.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _MAX_NUMBER_NODES 11 //MaxNumberOfNodes

#define _TEMPORARY_NODES 0

#define _PERMANENT_NODES 1

#define infinity 9999


int _Cut_move_won(); // the play function

int _FIND_SHORT_PATH(int _START_NODE ,

                     int _DESTINATION_NODE ,

                     int _SHORT_PATH[_MAX_NUMBER_NODES],

                     int *_SHORT_DISTANCE_DES); // Dijkstra algorithm

/*
 start initialize variable
 ***************************************************************
 */
int _map_of_game[_MAX_NUMBER_NODES][_MAX_NUMBER_NODES];

int _min_Distance[_MAX_NUMBER_NODES][_MAX_NUMBER_NODES];

int _nodes;

int _number_Of_Butterflies, _number_Of_Spiders;

int _position_of_butterfly[_MAX_NUMBER_NODES];

int _position_of_spider[_MAX_NUMBER_NODES];

int _adjacency_matrix[_MAX_NUMBER_NODES][_MAX_NUMBER_NODES];

// ************************ end ********************************

// start main function
int main(){
    
    printf("****************************************\n");

    printf("please enter the number of nodes:");

    scanf("%d", &_nodes);

    printf("\n\n");
    /*
     Input Validation
     number of nodes should be greater that 1 and less than number of nodes.
     */
    if (_nodes <= 1 || _nodes > _MAX_NUMBER_NODES)
    {
        printf("INVALID NUMBER OF NODES.\n");
        exit(1);
    }
    printf("****************************************\n");

    printf("please enter the map of the game (As a matrix) :\n");
    /*
     The map of game should be a symmetric diagonal matrix
     example :  0 0 1 1
     0 0 0 1
     1 0 0 0
     1 1 0 0
     
     */
    for (int i = 0; i < _nodes; i++) {

        for (int j = 0; j < _nodes; j++) {

            scanf( "%d", &_map_of_game[i][j]);
        }
    }
    printf("\n");

    printf("****************************************\n");

    printf("please enter the number of spider:");

    scanf("%d", &_number_Of_Spiders);
    /*
     Input Validation
     number of nodes should be greater that 1 and less than number of nodes.
     */
    if (_number_Of_Spiders < 1 || _number_Of_Spiders == _MAX_NUMBER_NODES)
    {
        printf("INVALID NUMBER OF SPIDERS.\n");

        exit(1);
    }
    
    printf("please enter the nodes which are spider's position:");
    /*
     Example: 2
     */
    for(int i=0; i<_number_Of_Spiders; i++) {

        scanf( "%d", &_position_of_spider[i]);
    }
    
    for(int i=0; i<_number_Of_Spiders; i++) {

        if(i != _number_Of_Spiders - 1) {

            printf("%d, ", _position_of_spider[i]);

        } else {

            printf("%d", _position_of_spider[i]);
        }

    } printf("\n\n");

    printf("****************************************\n");

    printf("please enter the number of butterfly:");

    scanf("%d", &_number_Of_Butterflies);
    /*
     Input Validation
     number of nodes should be greater that 1 and less than number of nodes.
     */
    if (_number_Of_Butterflies < 1 || _number_Of_Butterflies == _MAX_NUMBER_NODES)
    {
        printf("INVALID NUMBER OF BYTTERFLIES.\n");

        exit(1);
    }
    printf("please enter the nodes which are butterflie's position :");
    /*
     Example: 5 6 7 8
     */
    for(int i=0; i<_number_Of_Butterflies; i++) {

        scanf( "%d", &_position_of_butterfly[i]);
    }
    
    for(int i=0; i<_number_Of_Butterflies; i++) {

        if(i != _number_Of_Butterflies - 1) {

            printf("%d, ", _position_of_butterfly[i]);

        } else {

            printf("%d", _position_of_butterfly[i]);
        }

    } printf("\n\n");
    
    
    _Cut_move_won();

        return 0;
}


//########################################int _FIND_SHORT_PATH#####################################
struct node
{
    int starter;
    int dist;
    int status;
};

int _FIND_SHORT_PATH(int _START_NODE,

                     int _DESTINATION_NODE,

                     int _SHORT_PATH[_MAX_NUMBER_NODES],

                     int *_SHORT_DISTANCE_DES)
{
    for(int m=0; m<_nodes; m++) {

        for (int n = 0; n <_nodes; n++) {

            _adjacency_matrix[m+1][n+1]=_map_of_game[m][n];

        }
    }

    struct node state[_MAX_NUMBER_NODES];

    int i,min,count=0,current,newdist,u,v;

    *_SHORT_DISTANCE_DES=0;

    for(i=1;i<=_nodes;i++)
    {
        state[i].starter=0;

        state[i].dist = infinity;

        state[i].status = _TEMPORARY_NODES;

    }

    state[_START_NODE].starter=0;

    state[_START_NODE].dist = 0;

    state[_START_NODE].status = _PERMANENT_NODES;

    
    /*Starting from _sart_node node until destination is found*/
    current=_START_NODE;

    while(current!=_DESTINATION_NODE)

    {
        for(i=1;i<=_nodes;i++)

        {
            /*Checks for adjacent temporary nodes */
            if ( _adjacency_matrix[current][i] > 0 && state[i].status == _TEMPORARY_NODES )

            {
                newdist=state[current].dist + _adjacency_matrix[current][i];
                /*Checks for Relabeling*/
                if( newdist < state[i].dist )
                {
                    state[i].starter = current;

                    state[i].dist = newdist;
                }
            }
        }/*End of for*/
        
        /*Search for temporary node with minimum distand make it current node*/
        min=infinity;

        current=0;

        for(i=1;i<=_nodes;i++)

        {
            if(state[i].status == _TEMPORARY_NODES && state[i].dist < min)

            {
                min = state[i].dist;

                current=i;
            }
        }/*End of for*/
        
        if(current==0) /*If _sart_node or Sink node is isolated*/

            return 0;

        state[current].status=_PERMANENT_NODES;
    }/*End of while*/
    
    // Getting full path in array from destination to _sart_node
    while( current!=0 )
    {
        count++;

        _SHORT_PATH[count]=current;

        current=state[current].starter;

    }
    for(i=count;i>1;i--)

    {
        u=_SHORT_PATH[i];

        v=_SHORT_PATH[i-1];

        *_SHORT_DISTANCE_DES += _adjacency_matrix[u][v];
    }
    return (count);
}
//##################################### _Cut_move_won function ###############################
int _Cut_move_won(){

    int spiderTurnsNumber = 0;

    int spiderTurns[100];

    int butterflyWon,spiderWon;
    
    while(1) {

        int i, j;

        int _sart_node, _dest_node;

        int _the_select_butterfly,

        _the_select_spider,

        _the_select_distance,

        _the_next_spider_node;

        int _the_neighbor_Of_butterfly_node;

        int _butterfly_multi, _spider_multi;

        int _spiderIsGameOver;

        int _size_index;
        
        int _path[_MAX_NUMBER_NODES];

        int _shortdist, _count;

        int _path_short[_MAX_NUMBER_NODES], _distance_way;
        
        /* Use dijkstra algorithm's function for
         finding shortest distance between first spider and first butterfly.
         ******************************************************************
         _position_of_spider[0]    => means the first spider
         _position_of_butterfly[0] => means the first butterfly
         _path_short               => means the shortest path between first spider and first butterfly
         _distance_way             => means the number of distance between first spider and first butterfly
         ******************************************************************
         */
        _FIND_SHORT_PATH(_position_of_spider[0], _position_of_butterfly[0], _path_short, &_distance_way);
        
        if( _distance_way != 0) { // check the number of distance

            _the_select_butterfly = _position_of_butterfly[0];

            _the_select_spider = _position_of_spider[0];

            _the_select_distance =  _distance_way;

            _the_next_spider_node = _path_short[ _distance_way];

        }else {

            _the_select_distance = 9999;

        }
        _the_neighbor_Of_butterfly_node = _path_short[2];

        
        /* Use dijkstra algorithm's function for
         finding shortest distance between  spider and another butterflies.
         use two < for loop > to find distance between spider and all Butterflies
         and then update blow variables
         ******************************************************************
         _position_of_spider
         _position_of_butterfly
         _path_short
         _distance_way
         ******************************************************************
         */
        for (_butterfly_multi = 0; _butterfly_multi < _number_Of_Butterflies; _butterfly_multi++) {

            for(int _spider_multi=0; _spider_multi<_number_Of_Spiders; _spider_multi++) {

                _dest_node = _position_of_butterfly[_butterfly_multi];

                _sart_node = _position_of_spider[_spider_multi];

                if (_sart_node == 0 || _dest_node == 0)

                    return 1;
                
                _count = _FIND_SHORT_PATH(_sart_node, _dest_node, _path, &_shortdist);

                if (_shortdist != 0) {

                    printf("\nShortest distance between spider (node %d) and butterfly (node %d) is: %d\n", _sart_node, _dest_node,
                           _shortdist);

                    printf("the node which spider go:%d \n", _path[_shortdist]);

                    printf("node[near butterfly (which she should destroy the edge between it and her vertex)]:%d\n",
                           _path[2]);


                    if (_shortdist < _the_select_distance) {

                        _the_select_butterfly = _dest_node;

                        _the_select_spider = _sart_node;

                        _the_select_distance = _shortdist;

                        _the_next_spider_node = _path[_shortdist];

                        printf("   -- The Chosen Butterfly Node and The Spider Node Changed! --\n\n");

                        _the_neighbor_Of_butterfly_node = _path[2];
                    }
                    printf("Shortest Path is : ");

                    printf("\n count:%d \n", _count);

                    for(i=_count;i>1;i--)

                        printf("%d->",_path[i]);

                        printf("%d",_path[i]);

                        printf("\n");

                       _min_Distance[_butterfly_multi][_spider_multi] = _shortdist;
                }
                else {

                    _min_Distance[_butterfly_multi][_spider_multi] = 0;
                }
                
            }
        }
        int _disconnect = 0;

        for (int m=0;m<_number_Of_Butterflies;m++){

            for(int f=0; f<_number_Of_Spiders; f++) {

                if (_min_Distance[m][f] != 0) {
                    
                    _disconnect++;
                    
                    //printf("\n~~~~~~~~~~~~~~~~~There is a butterfly, not isolated!!!~~~~~~~~~~~~~~~~\n");
                }
            }
        }
        if(_disconnect!=0) {

            printf("\n The chosen butterfly node: %d and the chosen spider node: %d\n",
                   _the_select_butterfly, _the_select_spider);

            _spiderIsGameOver = 0;

        } else {

            printf("There are no edges between spiders' nodes and butterflies' nodes right now.");

            _spiderIsGameOver = 1;
        }

        if (_spiderIsGameOver == 0) {
            // Finding which spider[index]
            _size_index = _number_Of_Spiders;
            
            // Assume that element does not exists in array /
            int found = 0;

            int index;

            int toSearch = _the_select_spider;

            for(index=0; index<_size_index; index++)
            {
                /*
                 * If element is found in array then raise found flag
                 * and terminate from loop.
                 */
                if(_position_of_spider[index] == toSearch)
                {
                    found = 1;

                    break;
                }
            }
            spiderTurnsNumber++;

            printf("\n ~~~~~~ STEP.%d ~~~~~~  \n", spiderTurnsNumber);

            printf(" Spiders' Turn: Spider on node %d went to node %d\n", _position_of_spider[index], _the_next_spider_node);

            _position_of_spider[index] = _the_next_spider_node;

            if (_position_of_spider[index] != _the_select_butterfly) {

                _map_of_game[_the_select_butterfly - 1][_the_neighbor_Of_butterfly_node - 1] = 0;

                _map_of_game[_the_neighbor_Of_butterfly_node - 1][_the_select_butterfly - 1] = 0;

                printf("\n Butterflies' Turn: They Removed The Edge Between Node %d And %d. \n\n", _the_select_butterfly, _the_neighbor_Of_butterfly_node);

                
            } else {

                printf("Spider ate the butterfly on node %d. \n\n      ------- Spiders Won! --------  \n\n ", _the_next_spider_node);

                break;
            }
            
        } else {

            printf("\n\n      ------- Butterflies Won! -------- \n\n ");

            break;
        }

        if(spiderTurnsNumber == 10){
            
            break;
        }
    }
    return 0;
}
