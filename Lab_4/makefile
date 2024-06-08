TARGET = principal
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = inc
SRC_DIR = src
OBJS    = $(OBJ_DIR)/Cliente.o \
		  $(OBJ_DIR)/Comentario.o \
		  $(OBJ_DIR)/Compra.o \
		  $(OBJ_DIR)/DTNotificacion.o \
		  $(OBJ_DIR)/DTFecha.o \
		  $(OBJ_DIR)/DTidProducto.o \
		  $(OBJ_DIR)/DTDireccion.o \
		  $(OBJ_DIR)/CompraPorProducto.o \
		  $(OBJ_DIR)/ControladorU.o \
		  $(OBJ_DIR)/iControladorU.o \
		  $(OBJ_DIR)/ControladorV.o \
		  $(OBJ_DIR)/iControladorV.o \
		  $(OBJ_DIR)/Fabrica.o \
		  $(OBJ_DIR)/Menu.o \
		  $(OBJ_DIR)/Observer.o \
		  $(OBJ_DIR)/Producto.o \
		  $(OBJ_DIR)/ProductoEnPromocion.o \
		  $(OBJ_DIR)/Usuario.o \
		  $(OBJ_DIR)/Promocion.o \
		  $(OBJ_DIR)/Vendedor.o \
		  $(OBJ_DIR)/principal.o

CPP = g++
CPPFLAGS = -Wall -I$(INC_DIR)

$(TARGET) : $(OBJS)
	mkdir -p $(BIN_DIR)
	@$(CPP) $(CPPFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CPP) -c -MD $(CPPFLAGS) $< -o $@

-include $(OBJ_DIR)/*.d

.PHONY: clean
clean :
	@rm -r $(OBJ_DIR) $(BIN_DIR)
