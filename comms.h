/* SHT */
	/* 3 bits */
#define SHT1X_ADDR				0x00

	/* 5 bits */
#define SHT1X_CMD_M_TEMP		0x03
#define SHT1X_CMD_M_RH			0x05
#define SHT1X_CMD_R_SR			0x07
#define SHT1X_CMD_W_SR			0x06
#define SHT1X_CMD_S_RESET		0x1E

	/* 4 bits */
#define SHT1X_CRC_INIT			0x00


/* CH341 EEPROM */
	/* 3 bits */
#define CH341_ADDR				0x05

	/* 5 bits */
#define CH341_CMD_WRITE			0x00
#define CH341_CMD_READ			0x01


struct sht1x_status {
	int valid;

	unsigned int low_battery;
	unsigned int heater;
	unsigned int no_reload;
	unsigned int low_resolution;
};

#ifdef COMMS_C

/* Timing */
void sht1x_delay(void);
void sht1x_startup_delay(void);

/* Input */
int sht1x_in(void);

/* Output */
void sht1x_sck(int v);
void sht1x_out(int v);

/* Comms */
void sht1x_trans_start(int part1, int part2);
void sht1x_conn_reset(void);

#endif

/* Comms */
unsigned int sht1x_read(int bytes);
int sht1x_write(unsigned char data);

/* Control */
int sht1x_command(int addr, int cmd);
int sht1x_device_reset(void);

/* Device */
void sht1x_open(char *dev);
struct sht1x_status sht1x_read_status(void);
int sht1x_write_status(struct sht1x_status status);
void sht1x_close(void);
