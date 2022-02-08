#define SETBIT(x,y) (x)|=(1<<(y))


#define CLRBIT(x,y) (x)&=(~(1<<(y)))

#define GETBIT(x,y) (((x)>>(y))&0x01)


#define togglebit(x,y) (x)^=(1<<(y))


#define setfirstnibble(x) |= (x)|15


#define clearfirstnibble(x) (x) &= (~(15))

#define setlastnibble(x) (x)|=240

#define clearlastnibble(x) (x)&= ~(240)



#define togglefirstnibble(x) (x)^ = 15


#define togglelastnibble(x) (x)^= 240


#define CONCHELPER(B7,B6,B5,B4,B3,B2,B1,B0)		0b##B7##B6##B5##B4##B3##B2##B1##B0

#define CONCBIT(B7,B6,B5,B4,B3,B2,B1,B0)  CONCHELPER(B7,B6,B5,B4,B3,B2,B1,B0)
