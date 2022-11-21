#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER jaeger_ust

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./jaeger-tp.h"

#if !defined(_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TP_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
    jaeger_ust,
    start_span,

    /* Input arguments */
    TP_ARGS(
    	char*, o_name,
    	uint64_t, p_id,
        uint64_t, t_id,
        uint64_t, s_id,
        char*, f_name
    ),

    /* Output event fields */
    TP_FIELDS(
        ctf_string(op_name, o_name)
        ctf_integer(uint64_t, parent_id, p_id)
        ctf_integer(uint64_t, trace_id, t_id)
        ctf_integer(uint64_t, span_id, s_id)
        ctf_string(fun_name, f_name)
    )
)


#endif /* _TP_H */

#include <lttng/tracepoint-event.h>
