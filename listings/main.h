[...]
/* Definitions of environment analog values */
/* Value of analog reference voltage (Vref+), connected to analog voltage   */
/* supply Vdda (unit: mV).                                                  */
#define VDDA_APPLI                       (3300UL)
#define USE_DOUBLE_BUFFER

/* Definition of ADCx conversions data table size */
#define ADC_CONVERTED_DATA_BUFFER_SIZE   (1UL*158U) // uses double buffer to not stop the DMA

/* Init variable out of expected ADC conversion data range */
#define VAR_CONVERTED_DATA_INIT_VALUE    (__LL_ADC_DIGITAL_SCALE(LL_ADC_RESOLUTION_12B) + 1)
#define QUEUE_BLE_PACKETS_NO 22
#define SEND_BIN_NO 20
#define BIN_SENT_OFFSET 3
#define SEND_BIN_INITIAL_IDX 0
#define EXTREMA_SAMPLES_DISCARD_NO 16
#define TOTAL_SAMPLES_DISCARD_NO 48

#define MICRODOPPLER_MODE

#define MD_BIN_SUM_START 10
#define MD_BIN_SUM_NUMBER 60
#define MD_SUMS_PER_PACKET 30 /* max 30 ramps */
[...]