#ifndef DISK_H
#define DISK_H

enum DISK_ERR{IS_BIGGER};


class disk{
public:
    disk();
    disk(const disk&);
    ~disk();

    bool isBigger(disk *other);

    int getSize();
    int getNextSize();
    int getPrevSize();
    disk* getNext();

    void setSize(int);
    void setNext(disk*);

protected:
    int size;
    disk *next, *prev;

};

#endif // DISK_H
