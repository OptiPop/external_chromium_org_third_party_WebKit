/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RTCPeerConnectionHandlerChromium_h
#define RTCPeerConnectionHandlerChromium_h

#include "core/platform/mediastream/MediaStreamDescriptor.h"
#include "core/platform/mediastream/RTCPeerConnectionHandler.h"
#include "public/platform/WebRTCPeerConnectionHandler.h"
#include "public/platform/WebRTCPeerConnectionHandlerClient.h"
#include <wtf/OwnPtr.h>
#include <wtf/PassRefPtr.h>

namespace WebKit {
class WebMediaStream;
class WebRTCICECandidate;
class WebRTCSessionDescription;
}

namespace WebCore {

class RTCDataChannelHandler;

class RTCPeerConnectionHandlerChromium : public RTCPeerConnectionHandler, public WebKit::WebRTCPeerConnectionHandlerClient {
public:
    explicit RTCPeerConnectionHandlerChromium(RTCPeerConnectionHandlerClient*);
    virtual ~RTCPeerConnectionHandlerChromium();

    bool createWebHandler();

    virtual bool initialize(PassRefPtr<RTCConfiguration>, PassRefPtr<MediaConstraints>) OVERRIDE;

    virtual void createOffer(PassRefPtr<RTCSessionDescriptionRequest>, PassRefPtr<MediaConstraints>) OVERRIDE;
    virtual void createAnswer(PassRefPtr<RTCSessionDescriptionRequest>, PassRefPtr<MediaConstraints>) OVERRIDE;
    virtual void setLocalDescription(PassRefPtr<RTCVoidRequest>, WebKit::WebRTCSessionDescription) OVERRIDE;
    virtual void setRemoteDescription(PassRefPtr<RTCVoidRequest>, WebKit::WebRTCSessionDescription) OVERRIDE;
    virtual WebKit::WebRTCSessionDescription localDescription() OVERRIDE;
    virtual WebKit::WebRTCSessionDescription remoteDescription() OVERRIDE;
    virtual bool updateIce(PassRefPtr<RTCConfiguration>, PassRefPtr<MediaConstraints>) OVERRIDE;
    virtual bool addIceCandidate(WebKit::WebRTCICECandidate) OVERRIDE;
    virtual bool addStream(PassRefPtr<MediaStreamDescriptor>, PassRefPtr<MediaConstraints>) OVERRIDE;
    virtual void removeStream(PassRefPtr<MediaStreamDescriptor>) OVERRIDE;
    virtual void getStats(PassRefPtr<RTCStatsRequest>) OVERRIDE;
    virtual PassOwnPtr<RTCDataChannelHandler> createDataChannel(const String& label, const WebKit::WebRTCDataChannelInit&) OVERRIDE;
    virtual PassOwnPtr<RTCDTMFSenderHandler> createDTMFSender(PassRefPtr<MediaStreamComponent>) OVERRIDE;
    virtual void stop() OVERRIDE;

    // WebKit::WebRTCPeerConnectionHandlerClient implementation.
    virtual void negotiationNeeded() OVERRIDE;
    virtual void didGenerateICECandidate(const WebKit::WebRTCICECandidate&) OVERRIDE;
    virtual void didChangeSignalingState(WebKit::WebRTCPeerConnectionHandlerClient::SignalingState) OVERRIDE;
    virtual void didChangeICEGatheringState(WebKit::WebRTCPeerConnectionHandlerClient::ICEGatheringState) OVERRIDE;
    virtual void didChangeICEConnectionState(WebKit::WebRTCPeerConnectionHandlerClient::ICEConnectionState) OVERRIDE;
    virtual void didAddRemoteStream(const WebKit::WebMediaStream&) OVERRIDE;
    virtual void didRemoveRemoteStream(const WebKit::WebMediaStream&) OVERRIDE;
    virtual void didAddRemoteDataChannel(WebKit::WebRTCDataChannelHandler*) OVERRIDE;

    static WebKit::WebRTCPeerConnectionHandler* toWebRTCPeerConnectionHandler(RTCPeerConnectionHandler*);

private:
    OwnPtr<WebKit::WebRTCPeerConnectionHandler> m_webHandler;
    RTCPeerConnectionHandlerClient* m_client;
};

} // namespace WebCore

#endif // RTCPeerConnectionHandlerChromium_h
