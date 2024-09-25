
#ifndef  x
#define x
typedef           unsigned char               uint8_t ;
typedef            signed char                    sint8_t ;
typedef           unsigned short             uint16_t ;
typedef            signed short                  sint16_t  ;
typedef           unsigned long               uint32_t ;
typedef            signed long                   sint32_t ;
typedef        unsigned long long         uint64_t ;
typedef           signed long long            sint64_t ;
typedef                float                             float32_t ;
typedef              double                           float64_t ;


typedef struct
{
    uint32_t period ;
    char reason[100] ;
    char vacationStartDate[20] ;
}vacation ;


typedef enum
{
    developer = 1,
    devops ,
    dataAnalyst ,
    web ,
    embeddedSystem ,
    contentCreator ,
    videoEditor
}position;

typedef enum {
    active ,
    onLeave
} status ;


typedef struct
{
    sint16_t  id ;
    char name [50] ;
    position f ;
    float32_t salary ;
    status st ;
} employees ;


#endif
