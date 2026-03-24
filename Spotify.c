#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct spotify{
    char title[100];
    int queued;
    struct spotify *prev;
    struct spotify *next;
}spotify;

spotify *awal = NULL;
spotify *akhir = NULL;
spotify *current = NULL;

spotify* createSong(char *title, int q){
    spotify *s = (spotify*)malloc(sizeof(spotify));
    strcpy(s->title,title);
    s->queued = q;
    s->prev = NULL;
    s->next = NULL;
    return s;
}

void add(char *title){
    spotify *s = createSong(title,0);

    if(!awal){
        awal = akhir = current = s;
        return;
    }

    akhir->next = s;
    s->prev = akhir;
    akhir = s;
}

void delete(spotify *song){
    if(song->prev)
        song->prev->next = song->next;
    else
        awal = song->next;

    if(song->next)
        song->next->prev = song->prev;
    else
        akhir = song->prev;

    free(song);
}

void removeSong(char *title){
    spotify *temp = awal;

    while(temp){
        if(strcmp(temp->title, title) == 0){
            if(temp == current){
                if(current->next)
                    current = current->next;
                else
                    current = current->prev;
            }

            delete(temp);
            return;
        }

        temp = temp->next;
    }
}

void queue(char *title){
    if(!current){
        add(title);
        printf("%s\n",current->title);
        return;
    }

    spotify *s = createSong(title,1);

    s->next = current->next;
    s->prev = current;

    if(current->next)
        current->next->prev = s;
    else
        akhir = s;

    current->next = s;
}

void nextSong(){
    if(!current || !current->next){
        if(current) printf("%s\n",current->title);
        return;
    }

    spotify *old = current;
    current = current->next;

    if(old->queued)
        delete(old);

    printf("%s\n",current->title);
}

void backSong(){
    if(current && current->prev)
        current = current->prev;

    if(current)
        printf("%s\n",current->title);
}

void list(){
    spotify *temp = current;

    while(temp){
        printf("%s",temp->title);
        if(temp->next) printf(", ");
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    char input[200];

    while(fgets(input,sizeof(input),stdin)){
        input[strcspn(input,"\n")] = 0;
        if(strcmp(input,"EXIT")==0) break;
        else if(strcmp(input,"NEXT")==0)
            nextSong();
        else if(strcmp(input,"BACK")==0)
            backSong();
        else if(strcmp(input,"LIST")==0)
            list();
        else if(strncmp(input,"ADD ",4)==0)
            add(input+4);
        else if(strncmp(input,"QUEUE ",6)==0)
            queue(input+6);
        else if(strncmp(input,"REMOVE ",7)==0)
            removeSong(input+7);
    }

    return 0;
}