for (uint16_t i = 0;
		i < ADC_CONVERTED_DATA_BUFFER_SIZE - TOTAL_SAMPLES_DISCARD_NO;
		i++) {
			uhADCxConvertedData_q15[i] = ((int32_t) (uhADCxConvertedData[i
				+ EXTREMA_SAMPLES_DISCARD_NO]) * 65535U + 2047U) / 4095U
				- 32768U;
}