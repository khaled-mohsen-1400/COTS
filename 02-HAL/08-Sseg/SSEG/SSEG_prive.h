#define C_ANODE 0
#define C_CATHODE 1



#if HARDWARE == C_CATHODE

#define ZERO		0x3F
#define ONE			0x06
#define TWO			0x5B
#define THREE		0x4F
#define FOUR		0x66
#define FIVE		0x6D
#define SIX			0x7D
#define SEVEN		0x07
#define EIGHT		0x7F
#define NINE		0x6F
#define RESET       0x00

#elif HARDWARE == C_ANODE

#define ZERO		0x40
#define ONE			0x79
#define TWO			0x24
#define THREE		0x30
#define FOUR		0x19
#define FIVE		0x12
#define SIX			0x02
#define SEVEN		0x78
#define EIGHT		0x00
#define NINE		0x10
#define RESET       0xFF

#endif