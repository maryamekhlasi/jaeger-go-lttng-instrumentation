package lttng

import "C"

import (
	"time"
)

func ReportSpan(operationName string, parentID uint64, traceID uint64, spanID uint64, functionName string) {
	C.traceStartSpan(
		C.CString(operationName),
		C.uint64_t(parentID),
		C.uint64_t(traceID),
		C.uint64_t(spanID),
		C.CString(functionName),)
}
