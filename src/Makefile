CC:=gcc
CFLAGS:=-Wall -g -O0
LFLAGS:=-lm
PROG_EXEC:=autcel
DEPLOY_DIR:=bin
OUT_DIR:=out

# RUN ALL TASKS
all: clear $(PROG_EXEC) remove_object_files

#LINKING
$(PROG_EXEC): $(PROG_EXEC).o input_parser.o pbm_writer.o constants.o
	$(CC) -o $(DEPLOY_DIR)/$(PROG_EXEC) $(DEPLOY_DIR)/$(PROG_EXEC).o $(DEPLOY_DIR)/input_parser.o $(DEPLOY_DIR)/pbm_writer.o $(DEPLOY_DIR)/constants.o

#COMPILATION
$(PROG_EXEC).o: main.c input_parser.h pbm_writer.h constants.h
	$(CC) -c main.c -o $(DEPLOY_DIR)/$(PROG_EXEC).o $(CFLAGS)

input_parser.o: input_parser.c input_parser.h constants.h
	$(CC) -c input_parser.c -o $(DEPLOY_DIR)/input_parser.o $(CFLAGS)

pbm_writer.o: pbm_writer.c pbm_writer.h
	$(CC) -c pbm_writer.c -o $(DEPLOY_DIR)/pbm_writer.o $(CFLAGS)

constants.o: constants.c constants.h
	$(CC) -c constants.c -o $(DEPLOY_DIR)/constants.o $(CFLAGS)

# CLEAR DEPLOY DIR
clear:
	mkdir -p $(DEPLOY_DIR)
	rm -rf $(OUT_DIR)
	mkdir $(OUT_DIR)

# REMOVE OBJECT FILES
remove_object_files:
	rm -f $(DEPLOY_DIR)/*.o