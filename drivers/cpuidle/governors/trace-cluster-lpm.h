/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2023-2024, Qualcomm Innovation Center, Inc. All rights reserved.
 */

#if !defined(_TRACE_CLUSTER_LPM_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_CLUSTER_LPM_H

#undef TRACE_SYSTEM
#define TRACE_SYSTEM cluster_lpm

#include <linux/tracepoint.h>

TRACE_EVENT(cluster_pred_select,

	TP_PROTO(int index, u64 next_wakeup,
				int restrict_idx, int pred, u64 pred_us),

	TP_ARGS(index, next_wakeup, restrict_idx, pred, pred_us),

	TP_STRUCT__entry(
		__field(int, index)
		__field(u64, next_wakeup)
		__field(int, restrict_idx)
		__field(int, pred)
		__field(u64, pred_us)
	),

	TP_fast_assign(
		__entry->index = index;
		__entry->next_wakeup = next_wakeup;
		__entry->restrict_idx = restrict_idx;
		__entry->pred = pred;
		__entry->pred_us = pred_us;
	),

	TP_printk("idx:%d next_wakeup:%llu restrict_idx:%d pred:%d pred_us:%llu",
		 __entry->index, __entry->next_wakeup,
		__entry->restrict_idx, __entry->pred, __entry->pred_us)
);

TRACE_EVENT(cluster_pred_hist,

	TP_PROTO(int idx, u64 resi, u32 sample, u32 tmr),

	TP_ARGS(idx, resi, sample, tmr),

	TP_STRUCT__entry(
		__field(int, idx)
		__field(u64, resi)
		__field(u32, sample)
		__field(u32, tmr)
	),

	TP_fast_assign(
		__entry->idx = idx;
		__entry->resi = resi;
		__entry->sample = sample;
		__entry->tmr = tmr;
	),

	TP_printk("idx:%d resi:%llu sample:%u tmr:%u",
		 __entry->idx, __entry->resi,
		__entry->sample, __entry->tmr)
);

TRACE_EVENT(cluster_exit,

	TP_PROTO(int cpu, u32 idx, u32 suspend_param),

	TP_ARGS(cpu, idx, suspend_param),

	TP_STRUCT__entry(
		__field(int, cpu)
		__field(u32, idx)
		__field(u32, suspend_param)
	),

	TP_fast_assign(
		__entry->cpu = cpu;
		__entry->idx = idx;
		__entry->suspend_param = suspend_param;
	),

	TP_printk("first cpu:%d idx:%u suspend_param:0x%x", __entry->cpu,
		  __entry->idx, __entry->suspend_param)
);

TRACE_EVENT(cluster_enter,

	TP_PROTO(int cpu, u32 idx, u32 suspend_param),

	TP_ARGS(cpu, idx, suspend_param),

	TP_STRUCT__entry(
		__field(int, cpu)
		__field(u32, idx)
		__field(u32, suspend_param)
	),

	TP_fast_assign(
		__entry->cpu = cpu;
		__entry->idx = idx;
		__entry->suspend_param = suspend_param;
	),

	TP_printk("last cpu:%d idx:%u suspend_param:0x%x", __entry->cpu,
		  __entry->idx, __entry->suspend_param)
);

#endif /* _TRACE_QCOM_LPM_H */

#undef TRACE_INCLUDE_PATH
#define TRACE_INCLUDE_PATH .

#undef TRACE_INCLUDE_FILE
#define TRACE_INCLUDE_FILE trace-cluster-lpm

#include <trace/define_trace.h>
