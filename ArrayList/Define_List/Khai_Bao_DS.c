//Line
#define Maxlength 80
typedef char ElementType;
typedef int Position; 
typedef struct {
	ElementType Elements[Maxlength];
	Position    Last;
} Line; 
//List
#define Maxlength 100
typedef float ElementType;
typedef int Position; 
typedef struct {
	ElementType Elements[Maxlength];
	Position    Last;
} List; 
//Polygon
#define Maxlength 100
typedef struct{
	int X;
	int Y;
} ElementType;
typedef int Position; 
typedef struct {
	ElementType Elements[Maxlength];
	Position    Last;
} Polygon; 
// DaThuc
#define Maxlength 100
typedef int Position; 
typedef struct {
    double he_so;
    int bac;
} DonThuc;
struct DaThuc{
	DonThuc A[Maxlength];
	Position    so_luong;
}; 
// SinhVien
#define Maxlength 40
typedef int Position; 
typedef struct {
    char mssv[10];
    char hoten[50];
    float dlt;
    float dth1;
    float dth2;
} SinhVien;
typedef struct {
	SinhVien A[Maxlength];
	Position    n;
} List; 
