int progredir (char maze[10][10], int h, int l){

if (maze[h][l] != '0' && 'E'){
    return 0;
} 
if (maze[h][l] == 'S'){
    return 1;
} 

maze[h][l] = '1';

if (progredir(maze, h-1, l)){
    return 1;
}

if (progredir(maze, h, l+1)){
    return 1;
}

if (progredir(maze, h+1, l)){
    return 1;
}

if (progredir(maze, h, l-1)){
    return 1;
}

}