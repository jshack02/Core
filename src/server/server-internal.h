#ifndef SERVER_IMPL_H
#define SERVER_IMPL_H

#include <list>

#include "edisense-types.h"

typedef struct PutResult
{
	bool success;
	bool moved;
	node_t moved_to;
} PutResult;

PutResult handlePutRequest(MessageId mesg_id, device_t device_id, 
	time_t timestamp, time_t expiration, void *data, size_t data_len);

typedef struct GetResult
{
	std::list<struct data> values; 
	bool moved;
	node_t moved_to;
} GetResult;

GetResult handleGetRequest(MessageId mesg_id, 
	device_t deviceId, time_t lower_range, time_t upper_range);

typedef struct CanRecvResult 
{
    bool can_recv;
    float util;
} CanRecvResult;

CanRecvResult handleCanRecv(MessageId mesg_id, partition_t partition_id);

bool handleUpdatePartitionOwner(MessageId mesg_id, node_t new_owner, 
	partition_t partition_id);

bool handleJoinRequest(MessageId mesg_id, std::string &new_node);

bool handleLeaveRequest(MessageId mesg_id);

#endif /* SERVER_IMPL_H */