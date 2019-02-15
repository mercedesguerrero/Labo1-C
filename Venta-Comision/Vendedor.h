

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
eVendedor* newVendedorParametrizado(int _id, char* _nombre, int nivel, int _cant_prod_vendidos, float _monto_vendido);

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

char* cargarDescripcion(int valor);

int agregarVendedor(ArrayList* vendedores);
void mostrarVendedor(eVendedor* unVendedor);
void mostrarVendedores(ArrayList* lista);
int buscarVendedor(ArrayList* lista, int id);

int seleccionarNivel();

int calcularComision(eVendedor* unVendedor);

int filtrarPorExperto(eVendedor* unVendedor);
int filtrarPorEstandard(eVendedor* unVendedor);
int filtrarPorJunior(eVendedor* unVendedor);

int getInt(char* mensaje);

void eliminarVendedor(ArrayList* vendedores);
void modificarVendedor(ArrayList* vendedores);

int compararComisiones(void* x, void* y);
