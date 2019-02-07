

typedef struct{

    int id;
    char nombre[40];
    int nivel;
    int cant_prod_vendidos;
    float monto_vendido;
    float comision;
    int isEmpty;

}eVendedor;

eVendedor* newVendedor();
eVendedor* newVendedorParametrizado(int _id, char* _nombre, int nivel, int _cant_prod_vendidos, float _monto_vendido, float _comision, int _isEmpty);

int set_id(eVendedor* unVendedor, int valor);
int set_nombre(eVendedor* unVendedor, char* _nombre);
int set_nivel(eVendedor* unVendedor, int valor);
int set_cant_prod_vendidos(eVendedor* unVendedor, int valor);
int set_monto_vendido(eVendedor* unVendedor, float valor);
int set_comision(eVendedor* unVendedor, float valor);
int set_isEmpty(eVendedor* unVendedor, int valor);
int get_id(eVendedor* unVendedor);
char* get_nombre(eVendedor* unVendedor);
int get_nivel(eVendedor* unVendedor);
int get_cant_prod_vendidos(eVendedor* unVendedor);
float get_monto_vendido(eVendedor* unVendedor);
float get_comision(eVendedor* unVendedor);
int get_isEmpty(eVendedor* unVendedor);

void agregarVendedor(ArrayList* vendedores, int _nivel);
void mostrarVendedor(eVendedor* unVendedor);
void mostrarVendedores(ArrayList* lista);
int buscarVendedor(ArrayList* lista, int id);
