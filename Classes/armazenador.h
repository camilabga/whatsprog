typedef float valor;

class Lista_valor{
  private:
    valor *x;
    unsigned N;

  public:
    inline Lista_valor(): N(0), x(NULL){}
    Lista_valor(unsigned dim);
    Lista_valor(const Lista_valor &L);
    ~Lista_valor(void);
    unsigned getN();
    void insira_lista(valor V);
    valor primeiro_lista();
    void remover_primeiro_lista();
    void imprimir_lista();
};