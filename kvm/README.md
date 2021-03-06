# Mastering KVM Virtualization

## 第1節 KVM による仮想化の基本
Linux 仮想化における一般的な技術と，他の仮想化ソリューションと比較した場合の優位性について紹介します．
libvirt，QEMU，KVM の重要なデータ構造と内部実装について説明します．

- [第1章: Linux 仮想化について理解する](./ch01_Understanding_Linux_Virtualization.md)
- [第2章: 仮想化ソリューションとしてのKVM](./ch02_KVM_as_a_Virtualization_Solution.md)
  途中

## 第2節 仮想マシン管理のための libvirt と ovirt
libvirt を用いた KVM ハイパーバイザのインストール，設定，管理について扱います．
ネットワークやストレージ，仮想ハードウェア設定など，KVM のインフラストラクチャについて詳しく説明します．
仮想マシンのディスク管理だけでなく，ライフサイクルの管理やマイグレーション技術についても見ていきます．
コマンドラインツールである **virsh** や，GUI ツールの **virt-manager** を使いこなせるようになることを目指します．

- [第3章: KVM ハイパーバイザと libvirt，ovirt のインストール](./ch03_Installing_KVM_Hypervisor_libvirt_and_ovirt.md)
- [第4章: libvirt のネットワーク](./ch04_llibvirt_Networking.md)
- [第5章: libvirt のストレージ]()
- [第6章: 仮想ディスプレイデバイスとプロトコル]()
- [第7章: 仮想マシンのインストールと設定，およびライフサイクル管理]()
- [第8章: VM ディスクやテンプレート，スナップショットの作成と修正]()

## 第3節 KVM 仮想マシンの自動化・カスタマイズ・オーケストレーション


## 第4節 スケーラビリティ・モニタリング・チューニングとトラブルシューティング