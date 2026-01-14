/*
Find function (root){
    temp = root -> left ( as root -> left exist)
    return (temp -> right -> right... till it is not root or null)
}
Main Function (root){

    make a vector and curr = root

    while(curr != NULL){
        if(curr's left not exist){
            take curr in vector
            move curr to it's right
        }
        else{
            prev = Find(curr)
            if(prev's right not exist){
                point prev's right to curr
                move curr to it's left
            }
            else{
                make prev's right = NULL
                teke curr in vector
                move curr to it's right
            }
        }
    }
    return vector
}
*/